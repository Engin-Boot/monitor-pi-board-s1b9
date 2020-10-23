#include "packagereader.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include<QVector>
#include<QQmlContext>

packageReader::packageReader(QObject *parent) : QObject(parent) {}

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
    QJsonObject obj = doc.object();
    QJsonArray arr= obj["packages"].toArray();

    packagenames.clear();
    versions.clear();

    packagenames.reserve(arr.size()+1);
    versions.reserve(arr.size()+1);

    packagenames.append("PACKAGE NAME");
    versions.append("VERSION");

    for(int i=0;i<arr.size();i++)
    {
        QJsonObject jsonPck=arr[i].toObject();

        QString pckname=jsonPck["package_name"].toString();
        QString pckversion=jsonPck["version"].toString();

        //2 separate strings created
        packagenames.append(pckname);
        versions.append(pckversion);
    }

    emit packageNamesUpdated();
    emit versionsUpdated();

}

void packageReader::getPackages(const QString &path)
{
    QJsonDocument jsonreport = createDoc(path);
    parseDoc(jsonreport);
}

bool packageReader::initialize()
{
    mEngine.rootContext()->setContextProperty("PackageManager",this);
    //resetModel();

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty()){
        return false;
    }else{
        return true;
    }
}
