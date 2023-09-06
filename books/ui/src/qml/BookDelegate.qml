import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App

Item {
    required property QtObject book
    Button {
        flat: true
        property QtObject delete_mut
        anchors {
            right: parent.right
            top: parent.top
        }
        text: "X"
        onClicked: {
            console.log(`deleting Book(id=${book.id})`);
            delete_mut = App.delete_book(book.id);
            console.log(delete_mut.completed);
        }
    }
    ColumnLayout {
        anchors.fill: parent
        Label {
            text: `<b>Title:</b> ${book.title}`
        }
        Label {
            text: `<b>Author:</b> ${book.author}`
        }
        TextArea {
            text: book.content
        }
    }
}
