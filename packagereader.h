#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H
#include "package.h"
#include <QObject>
#include<QVector>

//extern QVector <package> packagelist;

class packageReader : public QObject
{
    Q_OBJECT
private:
     QVector <package> packagelist;
    QJsonDocument createDoc(const QString &path);
    void parseDoc(const QJsonDocument &doc);


public:

    explicit packageReader(QObject *parent = nullptr);
    Q_INVOKABLE void getPackages(const QString &path);
    Q_INVOKABLE void displayPackages();


signals:

};

#endif // PACKAGEREADER_H
