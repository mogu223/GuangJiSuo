import asyncio
import time
from directive import Directive


class TaskObserve:
    def __init__(self, client: any):
        self.client = client
        self.breaks = {}
        self.skipNextBlock = -1
        self.pause = None
        self.skipBreak = False

        self.skipToBlock = None
        self.skipToBlockAndNotExcute = None

        self.store = {}
        self.delay = 0
        self.isOver = False
        self.startTime = time.time()
        # 阻塞的原因
        self.blocked_reason = 'none'

    def options(self, options: any):
        if options is None:
            return
        if 'delay' in options:
            self.delay = options['delay']
        if 'breaks' in options:
            self.breaks = options['breaks']
        if 'skips' in options:
            self.skips = options['skips']
        pass

    def ref(self, key: str, defaultValue: any):
        self.store[key] = defaultValue
        return self.store[key]
        pass

    async def __blocked(self, blockId: str, flowId: str):
        self.blocked_reason = 'none'
        while True:
            # 这里必须加入一个asyncio.sleep,
            # 否则进入死循环的情况下，
            # 外部的协程无法加入事件循环队列，
            # 因为while循环不会结束，加入asyncio.sleep，则隔断了循环
            await asyncio.sleep(0.001)
            if self.skipNextBlock == 0:
                self.skipNextBlock = 1
                return True
            if self.skipNextBlock == 1:
                self.blocked_reason = 'skipNextBlock'
                continue
            # 主动结束任务
            if self.isOver is True:
                return False
            # 如果处于暂停中，则continue,否则往后执行
            if self.pause is not None:
                if self.pause is True:
                    self.blocked_reason = 'pause'
                    continue

            # 直接跳到指定的block，跳过的中间部分不需要执行
            # if self.skipToBlockAndNotExcute is not None:
            #     if self.skipToBlockAndNotExcute == blockId:
            #         continue
            #     else:
            #         return False
            # 直接跳到指定的block，跳过的中间部分需要执行
            # if self.skipToBlock is not None:
            #     if self.skipToBlock == blockId:
            #         continue
            #     else:
            #         return True
            # 加断点，如果没有断点，则执行
            if self.breaks.get(blockId, None) is None:
                return True
            else:
                # 有断点，这时判断是否跳过本次的断点
                if self.skipBreak is True:
                    self.skipBreak = False
                    return True
                else:
                    self.blocked_reason = 'break'
                    continue
        pass
    """
     块运行前判断，判断是否需要执行该块
     判断是一个阻塞的过程，
     需要界面调试器给出进一步的指示
    """
    async def _if(self, blockId: str, flowId: str = None) -> bool:
        if self.isOver:
            return False
        if self.delay > 0 and self.skipNextBlock != 1:
            await asyncio.sleep(self.delay)
        await self.client.send(Directive.run_block_start, {"blockId": blockId, "flowId": flowId})
        result = await self.__blocked(blockId, flowId)
        if result is True:
            return True
        else:
            return False
    """
    块结束后,
    需要同步当前的store信息
    """
    async def output(self, blockId: str, flowId: str = None):
        if self.isOver:
            return False
        await self.sendStore()
        await self.client.send(Directive.run_block_end, {
            "blockId": blockId, "flowId": flowId})
        pass

    async def sendStore(self):
        store = {}
        for key in self.store:
            value = self.store[key]
            if isinstance(value, list) and isinstance(value, str) and isinstance(value, bool) and isinstance(value, int) and isinstance(value, float) and isinstance(value, dict):
                store[key] = value
            else:
                store[key] = str(value)
        await self.client.send(Directive.sync_store, {"store": store})
        pass

    async def runTaskStart(self):
        await self.client.send(Directive.run_task_start)
        pass

    def clear(self):
        self.store = {}
        self.skipNextBlock = -1
        self.pause = None
        self.skipBreak = False

        self.skipToBlock = None
        self.skipToBlockAndNotExcute = None
        # 卡住的原因
        self.blocked_reason = 'none'
        pass

    async def debug(self, blockId: str, data):
        if isinstance(data, list) and isinstance(data, str) and isinstance(data, bool) and isinstance(data, int) and isinstance(data, float) and isinstance(data, dict):
            data = data
        else:
            data = str(data)
        await self.client.send(Directive.block_debug, {'blockId': blockId, "data": data})
        pass
