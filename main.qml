import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: _root
    visible: true
    width: 400
    height: 400
    title: "Пятнашки"

    Tile {
        width: _root.width / 4
        height: _root.height / 4
    }
}
