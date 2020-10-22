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

};

#endif // PACKAGEREADER_H
