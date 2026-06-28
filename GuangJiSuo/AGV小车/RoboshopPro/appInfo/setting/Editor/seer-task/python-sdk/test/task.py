import sys
sys.path.append('E:\\seer-code\\seer-task-python-sdk\\debugger')
sys.path.append('E:\\seer-code\\seer-task-python-sdk\\rbk')
from rbklib import rbklib
from sock import SeerServerSock
from client import WebClient
import json
# print(sys.path)


def SeerDebugTask():
    robot = rbklib("192.168.8.167")
    info = robot.robot_status_info_req()
    print(json.loads(info[1].decode('utf-8')) )
    pass

if __name__ == "__main__":
    SeerDebugTask()
    # seerSock = SeerServerSock()
    # seerSock.observe('taskId', SeerDebugTask)
    # seerSock.run()
