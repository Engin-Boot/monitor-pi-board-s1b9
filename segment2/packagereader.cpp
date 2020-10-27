/*******************************************************************************************************
* Qt GUI Application
* https://github.com/Engin-Boot/monitor-pi-board-s1b9/
*
* Copyright (c) 2020 Engin-Boot
* Released under MIT License
*
* Refer project root for license text
********************************************************************************************************/

#include "packagereader.h"

packageReader::packageReader(QObject *parent) : QObject(parent) {}

//Creating a JsonDocument from the JSON report file
QJsonDocument packageReader::createDoc(const QString &path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray val = file.readAll();
    file.close();
    
    QJsonDocument jsonreport = QJsonDocument::fromJson(val);
    return jsonreport;
}

//Parsing the JSON file content and storing it in QStringList(packagenames and versions)
void packageReader::parseDoc(const QJsonDocument &doc)
{
    QJsonObject obj = doc.object();
    QJsonArray arr= obj["packages"].toArray();

    packagenames.clear();
    versions.clear();

    //Reserving space for allocating elements.
    packagenames.reserve(arr.size()+1);
    versions.reserve(arr.size()+1);

    packagenames.append("PACKAGE NAME");
    versions.append("VERSION");

    for(int i=0;i<arr.size();i++)
    {
        QJsonObject jsonPck=arr[i].toObject();

        QString ind = QString::number(i);
        QString pckname=jsonPck["package_name"].toString();
        QString pckversion=jsonPck["version"].toString();

        //2 separate StringLists created
        packagenames.append(pckname);
        versions.append(pckversion);
    }

    emit packagesUpdated();
}

//******************Called in main***********************

void packageReader::getPackages(const QString &path)
{
    QJsonDocument jsonreport = createDoc(path);
    parseDoc(jsonreport);
}

//********************************************************

// Making packageReader class available to mail.qml
bool packageReader::initialize()
{
    mEngine.rootContext()->setContextProperty("PackageManager",this);

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty())
        return false;
    else
        return true;
}
