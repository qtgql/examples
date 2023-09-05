import QtQuick
import QtQuick.Controls

ListView {
    id: root
    clip: true
    spacing: 5
    anchors.fill: parent
    ScrollBar.vertical: ScrollBar {
        parent: root.parent
        anchors.top: root.top
        anchors.left: root.right
        anchors.bottom: root.bottom
    }
}
