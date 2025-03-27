import QtQuick          2.15
import QtQuick.Controls 2.15

ApplicationWindow 
{
    id: applicationWindow
    title: "setuav"
    visible: true
    width: 1280
    height: 720
    color: "#191919"

    property real margin: 8

    TopBar
    {
        id: topBar
        visible: true
        width: parent.width - margin * 2

        anchors {
            top: parent.top
            topMargin: margin
            left: parent.left
            leftMargin: margin
        }

        onWorkspaceChanged: (workspace) => {
            airframe.visible = workspace === "Airframe"
            propulsion.visible = workspace === "Propulsion"
            performance.visible = workspace === "Performance"
        }
    }

    Airframe
    {
        id: airframe
        visible: true
        width: parent.width - margin * 2
        height: parent.height - topBar.height - margin * 3

        anchors {
            top: topBar.bottom
            topMargin: margin
            left: parent.left
            leftMargin: margin
        }
    }

    Propulsion
    {
        id: propulsion
        visible: false
        width: parent.width - margin * 2
        height: parent.height - topBar.height - margin * 3

        anchors {
            top: topBar.bottom
            topMargin: margin
            left: parent.left
            leftMargin: margin
        }
    }

    Performance
    {
        id: performance
        visible: false
        width: parent.width - margin * 2
        height: parent.height - topBar.height - margin * 3

        anchors {
            top: topBar.bottom
            topMargin: margin
            left: parent.left
            leftMargin: margin
        }
    }
}