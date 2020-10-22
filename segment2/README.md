# Building Qt GUI Application

## Installation Guide

Installing Qt

* [Qt Online Installer](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)

* [Qt Offline Installer](https://download.qt.io/archive/qt/5.14/5.14.2/)

You can use anyone of the above installer to install Qt and use it to develop GUI applications.

## Table of Content

I. Parsing JSON report created by the [Core-Infra Team](https://github.com/Engin-Boot/monitor-pi-board-s1b11)

II. Developed a GUI Interface that displays the contents from JSON.

III. Results

IV. Reference

### I.  Parsing JSON report created by the [Core-Infra Team](https://github.com/Engin-Boot/monitor-pi-board-s1b11)

Accessing the JSON report file in Qt.

Then parsing the JSON report, As the JSON report has 2 Keys PackageName, Version so storing the content of JSON report in 2 variables packagenames,versions of type [QStringList](https://doc.qt.io/qt-5/qstringlist.html#:~:text=QStringListIterator-,Detailed%20Description,is%20both%20fast%20and%20safe.)



