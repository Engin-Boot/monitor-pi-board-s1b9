#ifndef PACKAGE_H
#define PACKAGE_H

#include <QObject>

class package : public QObject
{
  Q_OBJECT
    
private:
    QString packagename;
    QString version;
public:
    explicit package(QObject *parent = nullptr);
    explicit package(const package&);
    package & operator=(const package&);

    QString getPackagename() const;
    void setPackagename(const QString &value);

    QString getVersion() const;
    void setVersion(const QString &value);

     package& getPackage();


signals:

};

#endif // PACKAGE_H
