import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App

Pane {
    id: root
    anchors.fill: parent
    Label {
        text: `Books count: ${books_lv.count}`
        font.pixelSize: 50
    }
    ScrollView {
        height: parent.height
        anchors.centerIn: parent
        width: 400

        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        ListView {
            id: books_lv
            anchors.fill: parent

            model: App.allBooksQuery?.data.allBooks
            delegate: Pane {
                required property var model
                width: ListView.view.width
                height: 200
                BookDelegate {
                    anchors.fill: parent
                    book: model.data
                }
            }
        }
    }
}
