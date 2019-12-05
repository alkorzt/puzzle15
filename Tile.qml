import QtQuick 2.12

Rectangle {
    id: _root
    property string  displayText: ""
    color: "lightgreen"

    border.color: "green"
    border.width: 2
    radius: 20

    Text {
        text: _root.displayText
        anchors.centerIn: _root
        font {
           pointSize: Math.min(_root.width, _root.height) / 2
        }
    }
}
