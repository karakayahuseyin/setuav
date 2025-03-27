// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

import QtQuick              2.15
import QtQuick.Controls     2.15

Item
{
    id: propulsion
    width: parent.width 
    height: parent.height

    Rectangle
    {
        id: propulsionMenu
        width: parent.width
        height: parent.height
        color: "#232323"
        radius: 10
        border.color: "#494949"
        border.width: 0.5
    }

    Text {
        id: title
        text: "Propulsion"
        font.pixelSize: 20
        font.family: "Inter"
        font.bold: true
        color: "white"
        anchors.centerIn: parent
    }
}