import QtQuick

Window{id:root
    width: 500;
    height: 400;
    visible: true;
    property var continent: query?.data?.continent;

    Rectangle{
        anchors.fill: parent;
        color: "grey";

        ListView{id: countries_view
        anchors.fill: parent;
            model: root.continent?.countries;
            header: Text{
                text: `Countries in Continent ${root.continent?.name} (${countries_view.count})`
            }
            delegate: Item{                    id: country_delegate
                required property var model;
                property var view: ListView.view;
                width: view.width;
                height: 50;
                Text{
                    anchors.centerIn: parent;
                    property var country: country_delegate.model.data;
                    text: `${country_delegate.model.index}: ${country.emoji} ${country.capital}`
                }
            }
        }
        
    }
}