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
    ListView {
        id: books_lv
        height: parent.height
        anchors.centerIn: parent
        model: App.allBooksQuery?.data.allBooks
        width: 400
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
