import QtQuick 2.12

GridView {
    id: _root
    model: 16

    cellHeight: height / 4
    cellWidth:  width / 4

    delegate: Tile {
        width:  cellWidth
        height: cellHeight
    }
}
