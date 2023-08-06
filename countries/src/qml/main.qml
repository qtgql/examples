import QtQuick
import QtQuick.Layouts
Window{id:root
    width: 500;
    height: 400;
    visible: true;
    property var continent: query?.data?.continent;

    Rectangle{
        anchors.fill: parent;
        color: "grey";
        ColumnLayout{
        Text{
            text: `Continent ${root.continent?.name} Countries )`
        }
        ListView{id: countries_view
            model: root.continent?.countries
            delegate:
                Text{id: country_delegate
                    required property var model;
                    property var country: model.data;
                    text: ` ${country.emoji} ${country.capital}`
                }
        }
        }
    }
}