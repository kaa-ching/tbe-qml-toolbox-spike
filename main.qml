import QtQuick 2.0
import QtQuick.Layouts 1.2
import "gui"

RowLayout {
    id: window
    width: 800; height: 400

    function img(A) {
        return "image://tbe/"+A;
    }

    property real theScale: 250

   Rectangle {
        id: gameView

        Layout.fillWidth: true
        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
        Layout.preferredHeight: width * 0.5
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
        width: 200;
        Layout.fillHeight: true
        Layout.alignment: Qt.AlignRight
    }
}
