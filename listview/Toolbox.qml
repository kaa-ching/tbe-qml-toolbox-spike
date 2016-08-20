/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Controls 1.4
import "content"
//import "content/PaletteItem.qml"

Rectangle {

    // Delegate for the recipes.  This delegate has two modes:
    // 1. List mode (default), which just shows the picture and title of the recipe.
    // 2. Details mode, which also shows the ingredients and method.
    Component {
        id: recipeDelegate

        Item {
            id: recipe

            // Create a property to contain the visibility of the details.
            property bool isOpened : false

            width: listView.width
            height: 70

            // A simple rounded rectangle for the background
            Rectangle {
                id: background
                x: 2; y: 2; width: parent.width - x*2; height: parent.height - y*2
                color: "ivory"
                border.color: "orange"
                radius: 5
            }

            // This mouse region covers the entire delegate.
            // When clicked it changes mode to 'Details'.  If we are already
            // in Details mode, then no change will happen.
            //! [1]
            MouseArea {
                anchors.fill: parent
                onClicked: recipe.state = 'Details';
            }

            // Lay out the page: picture, title and ingredients at the top, and method at the
            // bottom.
            // Note that elements that should not be visible in the list track recipe.isOpened.

            Row {
                id: topLayout
                x: 10; y: 10; height: recipeImage.height; width: parent.width
                spacing: 10

                PaletteItem {
                    id: recipeImage
                    width: 50; height: 50
                    source: img(picture)
                }

                Column {
                    width: background.width - recipeImage.width - 20; height: recipeImage.height
                    spacing: 5

                    Text {
                        text: "%1x %2".arg(count).arg(name)
                        font.bold: true; font.pointSize: 14
                        wrapMode: Text.Wrap
                        visible: !recipe.isOpened
                    }
                    // A button to close the detailed view, i.e. set the state back to default ('').
                    Button {
                        visible: recipe.isOpened
                        text: "Close"

                        onClicked: recipe.state = '';
                    }
                }
            }

            Text {
                id: secondTitle
                anchors { top: topLayout.bottom }
                text: "%1x %2".arg(count).arg(name)
                font.bold: true; font.pointSize: 14
                wrapMode: Text.Wrap
                width: parent.width-14
                x: 10
                visible: recipe.isOpened
            }

            Text {
                id: tooltipText
                text: tooltip
                anchors { top: secondTitle.bottom }
                wrapMode: Text.Wrap
                width: parent.width-14
                x: 10
                visible: recipe.isOpened
            }


            states: State {
                name: "Details"

                PropertyChanges { target: background; color: "white" }
                PropertyChanges { target: recipeImage; width: theScale*owidth; height: theScale*oheight } // Make picture bigger
                PropertyChanges { target: recipe; isOpened: true; } // Make details visible
                PropertyChanges { target: recipe; height: tooltipText.height + secondTitle.height + 20 + recipeImage.height } // Ensure we can see the full tooltip+image

                // Move the list so that this item is at the top.
                PropertyChanges { target: recipe.ListView.view; explicit: true; contentY: recipe.y }

                // Disallow flicking while we're in detailed view
                PropertyChanges { target: recipe.ListView.view; interactive: false }
            }

            transitions: Transition {
                // Make the state changes smooth
                ParallelAnimation {
                    ColorAnimation { property: "color"; duration: 500 }
                    NumberAnimation { duration: 300; properties: "contentY,height,width" }
                }
            }
        }
    }

    // The actual list
    ListView {
        id: listView
        anchors.fill: parent
        model: RecipesModel {}
        delegate: recipeDelegate
    }
}
