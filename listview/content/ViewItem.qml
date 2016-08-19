import QtQuick 2.0

Image {
    property bool created: false
    property string image

    // TODO: Must be configurable (duh)
    width: 50
    height: 50

    // the is* properties are updated by the ViewItem
    property bool isHResize : false
    property bool isVResize : false
    property bool isRotate  : false
    property bool isColliding : false

    source: image

}
