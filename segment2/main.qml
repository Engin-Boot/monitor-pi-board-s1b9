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
            id : mListView

            width : parent.width/2
            model : packagenamelist
            delegate: Rectangle
            {

                width : parent.width
                height: 50
                color: "beige"
                border.color: "yellowgreen"

                Text {
                    width : parent.width
                    height: parent.height
                    id : textId
                    anchors.centerIn: parent
                    text : modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical:vbar
        }

        ListView{
            id : mListView2
            model : packageversionlist
            width : parent.width/2
            //anchors.left: mListView.right
            delegate: Rectangle{

                width : parent.width
                height: 50
                color: "beige"
                border.color: "yellowgreen"
                //radius: 5

                Text {
                    width :parent.width
                    height: parent.height
                    id : textId2
                    anchors.centerIn: parent
                    text : modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
            ScrollBar.vertical:vbar

        }
    }

    ScrollBar {
        id: vbar
        policy: ScrollBar.AlwaysOn
    }


    Component.onCompleted: {
        var t0 = new Date();
        PackageManager.getPackages("package-json-report.json");

        var t1 = new Date();
        console.log("Took: " + (t1.valueOf() - t0.valueOf()) + " milliseconds");

    }

}
