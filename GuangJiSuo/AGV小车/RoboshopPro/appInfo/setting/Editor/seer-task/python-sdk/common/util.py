

"""
将整数文本转成整数
defaultValue 表示转换不成功所取的整数值
"""
from datetime import datetime


def toInt(str: str, defaultValue: int = 0):
    try:
        va = int(str)
        return va
    except Exception as ex:
        return defaultValue


pass

"""
将浮点数文本转成浮点数
defaultValue  表示转换不成功所取的浮点数
"""


def toNumber(str: str, defaultValue: float = 0):
    try:
        val = float(str)
        return val
    except Exception as ex:
        return defaultValue


pass

"""
将文本按着指定的格式转成日期
如果转换失败，则取defaultDate,
如defaultDate为空，则取当前日期

"""


def toDate(str: str, format: str, defaultDate: datetime = datetime.now()):
    try:
        val = datetime.strptime(str, format)
        return val
    except Exception as ex:
        return defaultDate


pass

"""
判断数据的文本类型
"""


def isType(data: any, type: str = 'string'):
    if type == 'string':
        return isinstance(data, str)
    elif type == 'null':
        return data is None
    elif type == 'bool':
        return isinstance(data, bool)
    elif type == 'date':
        return isinstance(data, datetime)
    elif type == 'int':
        return isinstance(data, int)
    elif type == 'number':
        return isinstance(data, float)
    elif type == 'array':
        return isinstance(data, list)
    elif type == 'object':
        return isinstance(data, dict)
    else:
        return False
    pass


"""
将日期格式转成python日期库的格式
"""


def toDateFormat(dateFormat: str):
    dateFormat = dateFormat.replace("YYYY", "%Y")
    dateFormat = dateFormat.replace('MM', "%m")
    dateFormat = dateFormat.replace("DD", "%d")
    dateFormat = dateFormat.replace('HH', '%H')
    dateFormat = dateFormat.replace('hh', "%I")
    dateFormat = dateFormat.replace('mm', '%M')
    dateFormat = dateFormat.replace("ss", "%S")
    return dateFormat
    pass
