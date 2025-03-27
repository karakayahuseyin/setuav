// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

import QtQuick              2.15
import QtQuick.Controls     2.15
import QtQuick.Shapes       1.8

Rectangle {
    id: topBar
    width: parent.width - 40
    height: logoButton.height + 20
    radius: 10
    border.color: "#494949"
    border.width: 0.5
    color: "#232323"

    property string currentWorkspace: "Airframe"
    signal workspaceChanged(string workspace)

    // gradient: Gradient {
    //     orientation: Gradient.Horizontal
    //     stops: [
    //         GradientStop { position: 0.0; color: "#232323" },
    //         GradientStop { position: 0.5; color: "#1d1d1d" },
    //         GradientStop { position: 1.0; color: "#191919" }
    //     ]
    // }

    Button {
        id: logoButton
        background: Rectangle {
            implicitHeight: 40
            implicitWidth: 150
            color: "transparent"
            radius: 10
        }

        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        
        Image {
            id: logo
            source: "qrc:/img/logo.png"
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            width: 30
            height: 30
        }

        Text {
            id: title
            text: "SETUAV"
            font.pixelSize: 20
            font.family: "Inter"
            font.bold: true
            color: "white"
            anchors.left: logo.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }

        onClicked: {
            background.color = "#242424"
            background.border.color = "#494949"
            background.border.width = 0.5
        }
    }

    Row {
        id: workspaceButtons
        spacing: 30
        anchors.left: logoButton.right
        anchors.leftMargin: 40
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            model: ListModel {
                ListElement { name: "Airframe"; icon: "qrc:/img/airframe.svg" }
                ListElement { name: "Propulsion"; icon: "qrc:/img/propulsion.svg" }
                ListElement { name: "Performance"; icon: "qrc:/img/performance.svg" }
            }
            
            Button {
                id: button
                background: Rectangle {
                    implicitHeight: 28
                    implicitWidth: 160
                    color: currentWorkspace === model.name ? "#ff8844" : "transparent"
                    radius: 10
                }
                
                Row {
                    anchors.centerIn: parent
                    spacing: 8
                    
                    Image {
                        source: model.icon
                        width: 16
                        height: 16
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    
                    Text {
                        id: buttonText
                        text: model.name
                        font.pixelSize: 16
                        font.family: "Inter"
                        color: "white"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                
                onClicked: {
                    if (currentWorkspace !== model.name) {
                        currentWorkspace = model.name
                        workspaceChanged(model.name)
                    }
                }
            }
        }
    }
}