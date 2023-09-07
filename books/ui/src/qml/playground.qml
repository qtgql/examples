import QtQuick
import QtQuick.Controls.Material

Window {
    id: root
    width: 1200
    height: 900
    visible: true
    Material.theme: Material.Dark
    Material.accent: Material.Cyan

    Pane {
        anchors.fill: parent
        objectName: "_rootRect"
        Loader {
            id: loader
            objectName: "debug_loader"
            anchors.fill: parent
            source: "./RootRect.qml"
        }
    }
}
