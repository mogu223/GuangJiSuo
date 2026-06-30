#include "ErrorDatabase.h"

ErrorDatabase::ErrorDatabase(const QString& dbName)
{
    m_db.setDatabaseName(dbName);

    if (!m_db.open()) {
        qWarning() << "Database error:" << m_db.lastError().text();
        return;
    }

    // 创建包含时间字段的表结构
    QSqlQuery query;
    query.prepare(
        "CREATE TABLE IF NOT EXISTS error_info ("
        "error_code    INTEGER NOT NULL,"      // 错误码
        "sub_code      INTEGER NOT NULL,"     // 子错误码
        "description   TEXT,"                // 错误描述
        "action        TEXT,"                // 建议操作
        "create_time   DATETIME NOT NULL,"    // 新增时间字段
        "PRIMARY KEY (error_code, sub_code))" // 复合主键
        );

    if (!query.exec()) {
        qWarning() << "Create table error:" << query.lastError().text();
    }
}

bool ErrorDatabase::addError(const ErrInfo &err)
{
    QSqlQuery query;
    query.prepare(
        "INSERT OR REPLACE INTO error_info "
        "(error_code, sub_code, description, action, create_time) "
        "VALUES (:ec, :sc, :desc, :act, :ct)"
        );

    query.bindValue(":ec", err.error_code);
    query.bindValue(":sc", err.sub_code);
    query.bindValue(":desc", err.description);
    query.bindValue(":act", err.action);
    query.bindValue(":ct", QDateTime::currentDateTime());

    return executeQuery(query, "Insert error:");
}

QList<ErrInfo> ErrorDatabase::getAllErrors()
{
    QList<ErrInfo> errors;
    QSqlQuery query("SELECT error_code, sub_code, description, action FROM error_info");

    while (query.next()) {
        errors.append(ErrInfo{
            query.value(0).toInt(),  // error_code
            query.value(2).toString(), // description
            query.value(1).toInt(),  // sub_code
            query.value(3).toString() // action
        });
    }
    return errors;
}

bool ErrorDatabase::deleteError(int errorCode, int subCode)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM error_info "
        "WHERE error_code = :ec AND sub_code = :sc"
        );

    query.bindValue(":ec", errorCode);
    query.bindValue(":sc", subCode);

    return executeQuery(query, "Delete error:");
}



bool ErrorDatabase::executeQuery(QSqlQuery &query, const QString &errorPrefix)
{
    if (!query.exec()) {
        qWarning() << errorPrefix << query.lastError().text();
        return false;
    }
    return true;
}



QList<ErrInfo> ErrorDatabase::getErrorsByTime(const QDateTime &from, const QDateTime &to)
{
    QList<ErrInfo> errors;
    QSqlQuery query;
    query.prepare(
        "SELECT error_code, sub_code, description, action "
        "FROM error_info "
        "WHERE create_time BETWEEN :from AND :to"
        );
    query.bindValue(":from", from);
    query.bindValue(":to", to);

    if (query.exec()) {
        while (query.next()) {
            // 解析逻辑同getAllErrors
        }
    }
    return errors;
}

void ErrorDatabase::purgeOldData(int days)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM error_info "
        "WHERE create_time < datetime('now', '-' || :days || ' days')"
        );
    query.bindValue(":days", days);
    query.exec();
}
