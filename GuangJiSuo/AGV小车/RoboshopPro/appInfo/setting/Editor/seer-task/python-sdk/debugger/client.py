
import asyncio
import json
import sys
import os
from time import time
import websockets
import uuid
from directive import Directive
from observe import TaskObserve

"""
通信的基本数据格式
{id?:str,rid?:str,directive: Directions,data={}}
id:说明请求要回应
rid:说明是对刚才发起的请求的回应
无id,rid:仅仅只是推送消息
"""


class WebClient:
    def __init__(self, websocket: websockets, sock: any) -> None:
        self.id = uuid.uuid4()
        self.websocket = websocket
        remote_address = websocket.remote_address
        print(remote_address)
        print('connect websocket')
        self.sock = sock
        self.sendMessages = {}
        self.observer = TaskObserve(self)

    async def close(self):
        self.websocket.close()

    async def listen(self):
        while True:
            jm = None
            try:
                msg = await self.websocket.recv()
                jm = json.loads(msg)
                if jm.get('directive', None) == Directive.close_connect.value:
                    self.close()
                    break
            except websockets.ConnectionClosedOK:
                break
            finally:
                loop = asyncio.get_event_loop()
                if jm is None:
                    pass
                elif "rid" in jm:
                    loop.create_task(self.receiveByBeforeSend(jm))
                elif "id" in jm:
                    loop.create_task(self.receiveSync(jm))
                    pass
                else:
                    loop.create_task(self.receive(jm))
                    pass

    # 发送，只管发，不需要客户端有回应
    async def send(self, directive: Directive, data={}):
        await self.websocket.send(
            json.dumps({"directive": directive.value, "data": data}))

    # 发送后，有响应，回调函数接收响应
    async def sendSync(self, directive: Directive, data={}, callback=None):
        jsonMessage = {"id": uuid.uuid4(), "directive": directive,
                       "data": data}
        await self.websocket.send(json.dumps(jsonMessage))
        jsonMessage["callback"] = callback
        self.sendMessages[jsonMessage.id] = jsonMessage

    async def receiveByBeforeSend(self, data):
        msg = self.sendMessages[data.rid]
        if msg is not None:
            msg['callback'](data.data)
        pass

    # 接收信息
    async def receive(self, data={}):
        # print('receive')
        # print('receive:'+json.dumps(data))
        dr = data.get('data', None)
        dir = data.get('directive', None)
        if dir == Directive.run_task.value:
            if dr is not None:
                await self.sock.runTask(dr, self, dr.get("args",{}))
        elif dir == Directive.sync_breaks.value:
            self.observer.options({'breaks': dr.get('breaks',None)})
            pass
        # 暂停
        elif dir == Directive.run_pause.value:
            self.observer.pause = True
            pass
        # 继续
        elif dir == Directive.run_continue.value:
            self.observer.pause = None
            self.observer.skipNextBlock = -1
            pass
        # 跳到下一个断点处
        elif dir == Directive.skip_break.value:
            if self.observer.blocked_reason == 'break':
                self.observer.skipBreak = True
            self.observer.pause = None
            self.observer.skipNextBlock = -1
            pass
        # 下一步
        elif dir == Directive.skip_next_block.value:
            self.observer.skipNextBlock = 0
            self.observer.pause = None
            pass

        elif dir == Directive.skip_block.value:
            self.observer.skipToBlock = dr.get('blockId', None)
        elif dir == Directive.skip_block_no_excute.value:
            self.observer.skipToBlockAndNotExcute = True
        elif dir == Directive.skip_block_back.value:
            blockId = dr.get('blockId', None)
            self.observer.isOver = True
            self.observer.skipToBlockAndNotExcute = blockId
            self.observer.isOverClear = False
            pass

        elif dir == Directive.run_task_close.value:
            self.observer.isOver = True
            self.observer.isOverClear = dr.get('clear', True)
            pass

        elif dir == Directive.ping.value:
            print(dr.get('data', None))
            pass

        elif dir == Directive.sys_exit.value:
            #sys.exit(0)
            os._exit(0)
        else:
            print('receive not match any directive')
            print(data)
        pass

    # 接收信息，处理完后，直接发送
    async def receiveSync(self, data={}):
        pass
