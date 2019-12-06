import QtQuick 2.12
import QtQuick.Controls 2.12

Label {
    property int seconds: 0
    property double startTime: new Date().getTime()

    text: qsTr("Время: %1").arg(Math.ceil(seconds))

    Timer {
        interval: 50; running: true; repeat: true
        onTriggered: {
            seconds = (new Date().getTime() - startTime) / 1000;
        }
    }
}
