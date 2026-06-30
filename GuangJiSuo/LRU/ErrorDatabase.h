#ifndef ERRORDATABASE_H
#define ERRORDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>

#include "errorlist.h"


class ErrorDatabase
{
public:
    ErrorDatabase(const QString& dbName = "errors.db");

    // 插入数据时自动添加时间戳
    bool addError(const ErrInfo& err);
    // 读取时忽略时间字段
    QList<ErrInfo> getAllErrors();
    // 删除操作保持不变
    bool deleteError(int errorCode, int subCode);

    //扩展
    QList<ErrInfo> getErrorsByTime(const QDateTime& from, const QDateTime& to);
    // 清理旧数据
    void purgeOldData(int days);
private:
    QSqlDatabase m_db;
    bool executeQuery(QSqlQuery& query, const QString& errorPrefix);
};

#endif // ERRORDATABASE_H


/*
int main()
{
    ErrorDatabase db;

    // 插入数据（自动添加时间）
    ErrInfo err{404, "Not Found", 1, "Check URI"};
    db.addError(err);

    // 查询数据（不包含时间字段）
    auto errors = db.getAllErrors();
    qDebug() << "First error code:" << errors[0].error_code;

    // 删除数据
    db.deleteError(404, 1);

    return 0;
}

*/
