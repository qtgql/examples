import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtPositioning 5.2 as QP
import QtLocation 6.5 as QL
import com.library.tzv5hob
import Qt.labs.animation

Pane {
    id: root
    anchors.fill: parent
    ComboBox {
        id: providersCheckBox
        width: 150
        anchors {
            left: parent.left
            top: parent.top
        }
        model: map_item.supportedMapTypes
        onModelChanged: {
            currentIndex = 3;
        } // night transit by default
        textRole: "name"
        z: 9999
        delegate: ItemDelegate {
            implicitWidth: parent.width
            required property var model
            Label {
                text: `${map_item.supportedMapTypes[model.index].name}`
            }
        }
    }
    SideBar {
        id: side_bar
        // Material.background: Material.BlueGrey
        anchors.right: parent.right
        width: 350
        height: parent.height
    }
    GISMap {
        id: map_item
        anchors.right: side_bar.left
        anchors.left: parent.left
        height: parent.height
        zoomLevel: Tzv5hob.currentMapZoom
        Connections {
            target: Tzv5hob
            function onCurrentMapZoomChanged() {
                console.log("setting zoom level");
                map_item.zoomLevel = Tzv5hob.currentMapZoom;
            }
        }
        center: Tzv5hob.currentMapCenter
        activeMapType: providersCheckBox.currentValue ? providersCheckBox.currentValue : supportedMapTypes[4]
    }
}
