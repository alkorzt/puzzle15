import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.2

Window {
    id: _root
    visible: true
    width: 400
    height: 400
    title: "Пятнашки"

    GameBoard  {
        anchors.fill: parent
        anchors.bottomMargin: parent.height - _timer.y
        onTileMoved: _moveCounter.increment()
        onSolved: {
            _solvedDialog.open()
            _moveCounter.updateBestScore();
            _solvedDialog.open();
        }
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

    MoveCounter{
        id: _moveCounter
        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 5
            rightMargin: 10
        }

        font {
            pointSize: parent.height / 4 * 0.15;
        }
    }

    MessageDialog {
        property bool lastAnswerIsYes: false
        id: _solvedDialog
        title: qsTr("Решено!")
        text: qsTr("Хотите попробовать еще?")
        standardButtons: StandardButton.Yes | StandardButton.No
        icon: StandardIcon.Question
        onYes: {
            lastAnswerIsYes = true;
            _gameBoard.restartGame();
            _moveCounter.resetCurrentCount();
         }
         onNo: Qt.quit()
     }
}
