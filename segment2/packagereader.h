/*******************************************************************************************************
* Qt GUI Application
* https://github.com/Engin-Boot/monitor-pi-board-s1b9/
*
* Copyright (c) 2020 Engin-Boot
* Released under MIT License
*
* Refer project root for license text
********************************************************************************************************/

#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QQmlContext>

class packageReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList packagenames MEMBER packagenames NOTIFY packagesUpdated)
    Q_PROPERTY(QStringList versions MEMBER versions NOTIFY packagesUpdated)

private:
    QStringList packagenames;
    QStringList versions;
    
    QQmlApplicationEngine mEngine;
    
    QJsonDocument createDoc(const QString &path);
    void parseDoc(const QJsonDocument &doc);

public:
    bool initialize();
    Q_INVOKABLE void getPackages(const QString &path);
    explicit packageReader(QObject *parent = nullptr);
    
signals:
    void packagesUpdated();
};

#endif // PACKAGEREADER_H
