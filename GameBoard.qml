import QtQuick 2.12
import Game 1.0

GridView {
    id: _root

    move: Transition {
        NumberAnimation {
            properties: "x,y";
            duration: 2000;
        }
    }

    signal tileMoved();
    signal solved()

    cellHeight: height / _root.model.dimension
    cellWidth:  width / _root.model.dimension

    delegate: Rectangle {
        id: _backgroundDelegate
        width:  _root.cellWidth
        height: _root.cellHeight
        color: "lightcyan"

        visible: display !== _root.model.hiddenElementValue

        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 2

            displayText: display
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    _root.model.move(index);
                }
            }
        }
    }

    GameController{
        id: _gameController
        onTileMoved: _root.tileMoved();
        onSolved: root.solved()
    }

    function restartGame() {
        _gameController.restartGame()
    }

    Component.onCompleted: {
        _root.model = _gameController.getModel();
    }
}
