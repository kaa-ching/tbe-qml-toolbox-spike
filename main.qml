import QtQuick 2.0
import "listview"

Row {
    id: masterpage
    width: 800; height: 400

    Rectangle {
        id: view
        anchors { left: parent.left; top: parent.top; right: toolbox.left}
        height: width * 0.5
        border.color: "black"

        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#6baaf1";
            }
            GradientStop {
                position: 0.64;
                color: "#ffffff";
            }
            GradientStop {
                position: 0.98;
                color: "#175800";
            }
        }
    }

    Toolbox {
        id: toolbox
        width: 250;
        anchors {right: parent.right; top: parent.top; bottom: parent.bottom}
    }
}
