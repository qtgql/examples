import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App

Pane {
    id: root
    anchors.fill: parent
    ListView {
        height: parent.height
        anchors.centerIn: parent
        model: App.allBooksQuery?.data.allBooks
        delegate: Pane {
            required property var model
            property var book: model.data
            width: 100
            height: 100
            Label {
                text: `${book.title}`
            }
        }
    }
}
