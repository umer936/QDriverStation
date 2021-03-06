/*
 * Copyright (c) 2015 Alex Spataru <alex_spataru@outlook.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

import QtQuick 2.0

Item {

    //--------------------------------------------------------------------------
    // Custom properties
    //--------------------------------------------------------------------------

    property bool powered: false
    property alias text: label.text
    property alias radius: button.radius
    property alias ledWidth: button.width
    property alias ledHeight: button.height
    property alias color: button.background

    //--------------------------------------------------------------------------
    // Properties
    //--------------------------------------------------------------------------

    id: led
    width: childrenRect.width
    height: childrenRect.height

    Behavior on opacity { ColorAnimation{} }

    //--------------------------------------------------------------------------
    // Objects
    //--------------------------------------------------------------------------

    Button {
        id: button
        radius: width / 2
        background: "#f00"
        foreground: background
        width: q_app.scale (16)
        height: q_app.scale (16)

        Rectangle {
            color: "#000"
            anchors.fill: parent
            radius: parent.radius
            anchors.centerIn: parent
            opacity: led.powered ? 0 : 0.8

            Behavior on opacity { NumberAnimation{} }
        }
    }

    Label {
        id: label
        anchors {
            left: button.right
            leftMargin: q_app.scale (4)
            verticalCenter: button.verticalCenter
        }
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
        onPressed: parent.powered = !parent.powered
    }
}
