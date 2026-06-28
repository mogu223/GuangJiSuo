import asyncio
import websockets
from client import WebClient
from directive import Directive

"""
https://websockets.readthedocs.io/en/8.1/
"""

class SeerServerSock:

    def __init__(self, port=19100, ip="127.0.0.1"):
        self.ip = ip
        self.port = port
        self.tasks = {}
        self.clients = {}
        pass

    def __del__(self,):
        pass

    def observe(self, taskId: str, fun):
        self.tasks[taskId] = fun
        pass

    async def runTask(self, task: any, client: WebClient, args: dict):
        taskFun = self.tasks.get(task.get('taskId', None), None)
        client.observer.options(task.get('options', None))
        if taskFun is not None:
            try:
                await taskFun(task, client, args)
            except Exception as e:
                await client.send(Directive.run_task_error, {"error": str(e)})
                print(e)
                pass
            finally:
                if client.observer.skipToBlockAndNotExcute is not None:
                    await self.runTask(task, client, args)
                else:
                    client.observer.clear()
                    await client.send(Directive.run_task_end)
            pass
        pass

    async def receiveClient(self, websocket, path):
        cli = WebClient(websocket, self)
        self.clients[cli.id] = cli
        await cli.listen()
        del self.clients[cli.id]
        pass

    async def sock(self):
        print('open web socket '+self.ip+':'+str(self.port))
        # "ws://localhost:8765"
        # async with websockets.serve(self.receiveClient, self.ip, self.port):
        async with websockets.serve(ws_handler=self.receiveClient, host=self.ip, port=self.port):
            await asyncio.Future()  # run forever
        pass

    def run(self):
        loop = asyncio.get_event_loop()
        loop.run_until_complete(self.sock())
        loop.close()
        # asyncio.run(self.sock())
        pass
