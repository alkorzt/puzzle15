import QtQuick 2.12

Rectangle {
    id: _root
    color: "lightgreen"

    border.color: "green"
    border.width: 2
    radius: 20

    Text {
        text: "1"
        anchors.centerIn: _root
        font {
           pointSize: Math.min(_root.width, _root.height) / 2
        }
    }
}
