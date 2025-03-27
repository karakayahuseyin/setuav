import QtQuick              2.15
import QtQuick.Controls     2.15

Item
{
    id: performance
    width: parent.width
    height: parent.height

    Rectangle
    {
        id: performanceMenu
        width: parent.width
        height: parent.height
        color: "#232323"
        radius: 10
        border.color: "#494949"
        border.width: 0.5
    }

    Text {
        id: title
        text: "Performance"
        font.pixelSize: 20
        font.family: "Inter"
        font.bold: true
        color: "white"
        anchors.centerIn: parent
    }
}