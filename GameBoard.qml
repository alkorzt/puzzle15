import QtQuick 2.12
import Game 1.0

GridView {
    id: _root
    model: GameBoardModel {
    }

    cellHeight: height / 4
    cellWidth:  width / 4

    delegate: Rectangle {
        id: _backgroundDelegate
        width:  _root.cellWidth
        height: _root.cellHeight
        color: "lightcyan"

        visible: display !== 16

        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 2

            displayText: display
        }
    }
}
