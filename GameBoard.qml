import QtQuick 2.12
import Game 1.0

GridView {
    id: _root
    model: GameBoardModel {
    }

    cellHeight: height / _root.model.dimension
    cellWidth:  width / _root.model.dimension

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
