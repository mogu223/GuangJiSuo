#ifndef ERRORLIST_H
#define ERRORLIST_H
#include <QString>
#include <QObject>

struct ErrInfo
{
    int error_code;
    QString description;
    int sub_code;
    QString action;

    // 比较运算符重载
    bool operator==(const ErrInfo& other) const
    {
        return error_code == other.error_code &&
               sub_code == other.sub_code &&
               description == other.description &&
               action == other.action;
    }
};
Q_DECLARE_METATYPE(ErrInfo) // 注册元类型以支持信号槽传递

const ErrInfo Error_List[] =
{

    {0xA001,"AGV",0x001,"Restart AGV"},
    {0xA002,"Levelling",0x001,"Restart AGV"},
    {0xA003,"Lift",0x001,"Restart AGV"}
};

#endif // ERRORLIST_H
