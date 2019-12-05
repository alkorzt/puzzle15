import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: _root
    visible: true
    width: 400
    height: 400
    title: "Пятнашки"

    GameBoard  {
        anchors.fill: parent
    }
}
