#include "package.h"

QString package::getPackagename() const
{
    return packagename;
}

void package::setPackagename(const QString &value)
{
    packagename = value;
}

QString package::getVersion() const
{
    return version;
}

void package::setVersion(const QString &value)
{
    version = value;
}

package& package::getPackage()
{
    return *this;
}

package::package(QObject *parent) : QObject(parent)
{

}

package::package(const package & pck)
{
    this->packagename=pck.packagename;
    this->version=pck.version;
}

package &package::operator=(const package &pck)
{
    this->packagename=pck.packagename;
    this->version=pck.version;
    return *this;
}

