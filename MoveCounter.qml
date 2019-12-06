import QtQuick 2.0
import Game 1.0
import QtQuick.Controls 2.5

Label {
    text: qsTr("Ходов: %1").arg("")

    function increment() {
        _moveCounterController.increment()
    }

    MoveCounterController {
        id: _moveCounterController
    }
}
