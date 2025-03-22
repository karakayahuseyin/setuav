import QtQuick          2.15
import QtQuick.Controls 2.15

ApplicationWindow
{
    id:                         applicationWindow
    title:                      "Setuav"
    visible:                    true
    width:                      1280
    height:                     720

    Rectangle
    {
        id:                     rectangle
        color:                  "orange"
        anchors.fill:           parent

        Text
        {
            id:                 text
            text:               "Hello World"
            color:              "white"
            font.pixelSize:     24
            anchors.centerIn:   parent
        }
    }
}