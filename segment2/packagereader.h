#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H
#include<string>
#include <QObject>
#include<QVector>
#include<QQmlApplicationEngine>

class packageReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList packagenames MEMBER packagenames NOTIFY packagesUpdated)
    Q_PROPERTY(QStringList versions MEMBER versions NOTIFY packagesUpdated)

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

signals:
    void packagesUpdated();
};

#endif // PACKAGEREADER_H
