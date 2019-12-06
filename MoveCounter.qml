import QtQuick 2.0
import Game 1.0
import QtQuick.Controls 2.5

Label {
    property string bestScoreStr: _moveCounterController.bestScore === -1 ? "-" : _moveCounterController.bestScore;
    text: qsTr("Ходов: %1 | Рекорд: %2").arg(_moveCounterController.currentMovesValue).arg(bestScoreStr)

    function increment() {
        _moveCounterController.increment()
    }

    function updateBestScore() {
        _moveCounterController.updateBestScore()
    }

    MoveCounterController {
        id: _moveCounterController
    }
}
