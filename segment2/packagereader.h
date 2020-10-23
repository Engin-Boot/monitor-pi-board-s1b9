#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H
#include "package.h"
#include <QObject>
#include<QVector>
#include<QQmlApplicationEngine>

Q_DECLARE_METATYPE(QStringList);
class packageReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList packagenames MEMBER packagenames NOTIFY packageNamesUpdated)
    Q_PROPERTY(QStringList versions MEMBER versions NOTIFY versionsUpdated)

private:

    QJsonDocument createDoc(const QString &path);
    void parseDoc(const QJsonDocument &doc);
    QQmlApplicationEngine mEngine;
    QStringList packagenames;
    QStringList versions;
public:

    explicit packageReader(QObject *parent = nullptr);
    Q_INVOKABLE void getPackages(const QString &path);

    bool initialize();

    void resetModel();

signals:
    void packageNamesUpdated();
    void versionsUpdated();

};

#endif // PACKAGEREADER_H
