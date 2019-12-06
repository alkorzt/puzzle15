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
        anchors.bottomMargin: parent.height - _timer.y
    }

    TimerLabel {
        id: _timer
        anchors {
            left: parent.left
            bottom: parent.bottom
            margins: 5
            leftMargin: 10
        }
        font {
           pointSize: parent.height / 4 * 0.15;
        }
    }
}
