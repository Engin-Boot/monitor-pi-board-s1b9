#include "packagereader.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include<QVector>
packageReader::packageReader(QObject *parent) : QObject(parent)
{

}
QJsonDocument packageReader::createDoc(const QString &path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray val = file.readAll();
    file.close();
    QJsonDocument jsonreport = QJsonDocument::fromJson(val);
    return jsonreport;
}

void packageReader::parseDoc(const QJsonDocument &doc)
{
    QJsonArray arr=doc.array();
    packagelist.clear();
    packagelist.reserve(arr.size());

    for(int i=0;i<arr.size();i++)
    {
        QJsonObject jsonPck=arr[i].toObject();
        package pckobj;
        pckobj.setPackagename(jsonPck["package_name"].toString());
        pckobj.setVersion(jsonPck["version"].toString());
        packagelist.append(pckobj);
    }


}


void packageReader::getPackages(const QString &path)
{
    QJsonDocument jsonreport = createDoc(path);
    parseDoc(jsonreport);
    displayPackages();

}

void packageReader::displayPackages()
{
    for(int i=0;i<packagelist.size();i++)
    {
        qDebug()<<packagelist[i].getPackagename()<<" "<<packagelist[i].getVersion();
    }

}

