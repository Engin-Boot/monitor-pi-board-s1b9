import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Json Report")

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        ListView{
            id : mListViewPackageNames
            model : PackageManager.packagenames
            delegate: Rectangle
            {
                width : parent.width
                height: 50
                color: "beige"
                border.color: "yellowgreen"

                Text {
                    id : textIdPackageNames
                    anchors.centerIn: parent
                    text : modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical:vbar
        }

        ListView{
            id : mListViewVersions
            model : PackageManager.versions
            delegate: Rectangle
            {
                width : parent.width
                height: 50
                color: "beige"
                border.color: "yellowgreen"

                Text {
                    id : textIdVersions
                    anchors.centerIn: parent
                    text : modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical:vbar
        }
    }

    ScrollBar {
        //Scrollbar is used to connect both the ListView and both should scroll simultaneously
        id: vbar
        policy: ScrollBar.AlwaysOn
    }


    Component.onCompleted: {
        var t0 = new Date();

        //getPackage(path_where_JSON_file_is_present)
        PackageManager.getPackages("../segment2/package-json-report.json");

        var t1 = new Date();

        //Display in the console the time required to complete the task
        console.log("Took: " + (t1.valueOf() - t0.valueOf()) + " milliseconds to fetch " +
                    (mListViewVersions.count - 1) + " packages");

    }

}
