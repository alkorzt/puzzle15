import QtQuick 2.12

GridView {
    id: _root
    model: 16

    cellHeight: height / 4
    cellWidth:  width / 4

    delegate: Rectangle {
        id: _backgroundDelegate
        width:  _root.cellWidth
        height: _root.cellHeight
        color: "lightcyan"

        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 2
        }
    }
}
