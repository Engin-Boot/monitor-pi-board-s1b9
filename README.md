# Build Qt GUI application on Raspberry Pi3 board (Pi board)

Case Study by [Krishna Chaithanya](https://github.com/chaithubk)

This case study involves two segments

* Building an Embedded Linux distro for Pi board using
[Yocto Project](https://www.yoctoproject.org/)
* Design and develop a Qt QML GUI application that runs on Pi board

## [Segment 1] - Build Linux Distribution

This segment is to get you familiar with Core Infrastructure
aspects of board bring up.
You can accomplish this in stages:

* Setup and Build Linux Image
* Design and Develop a Yocto meta-stats layer
* Generate JSON reports via meta layer
* Generate SDK for Application development

### Setup and Build Linux Image

This stage involves getting you familiar
with the Build environment and creating a minimal Linux image.

Perform these activities:

* Setup Yocto Build Environment on Ubuntu
* Build core-image-sato image for Pi board
* Load the image on to board and verify that device boots up

### Design and Develop a Yocto meta-stats layer

This stage involves creation of a custom meta layer
to create a report with below details:

List of OSS (Open Source Software) packages installed

* Package name
* Package version
* Package Source Location

### Generate a JSON reports via meta layer

A JSON report with all the above mentioned details for each package
installed into the Linux image.

### Generate SDK for Application Development

Generate SDK (Software Development Kit) out of the Yocto build process,
which any application developer may use and compile his applications
to run on Pi board.

## [Segment 2] - Design and Develop Qt GUI application

This segment is to get you familiar with GUI Application Development
using [Qt Framework](https://www.qt.io/). You can accomplish this in stages:

* Build a minimal Qt QML application to run on Windows Desktop environment
* Cross compile the above application for the Pi board
using Core Infra delivered SDK
* Parse the JSON report from meta-stats layer and build a Data Model
* Develop a logic to measure Pi board performance
and run time device usage stats
* Develop an GUI Interface that displays
Packages & Performance stats in an intuitive way
