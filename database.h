/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static bool createConnection(const QString &tableName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":bda:");
    if (!db.open()) {
        qCritical() << "Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit.";
        return false;
    }

    QSqlQuery query;

    query.exec(QString("create table %1 (id int primary key, value real)").arg(tableName));
    return true;
}

static uint insertData(double *data, int n, /*QSqlDatabase db,*/ const QString &tableName)
{
    QSqlQuery query;

    uint retVal = 0;

    for(int i = 0; i < n; i++) {
        if (query.exec(QString("insert into %1 values(%2, %3)").arg(tableName).arg(i).arg(*data)))
            retVal++;
        data++;
    }
    return retVal;
}

static bool insertData(double value, int id,/*QSqlDatabase db, */const QString &tableName)
{
    QSqlQuery query;

    return query.exec(QString("insert into %1 values(%2, %3)").arg(tableName).arg(id).arg(value));
}

static uint getCountData(const QString &tableName)
{
    QSqlQuery query;
    query.exec(QString("SELECT COUNT(*) FROM %1 ").arg(tableName));
    return query.boundValue(1).toInt();
}


static bool clearTable(const QString &tableName)
{
    QSqlQuery query;

    return query.exec(QString("TRUNCATE TABLE %1").arg(tableName));
}

#endif


