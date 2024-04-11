#include "List.h"

namespace View::ListRenderer{
    void List::render(QGridLayout* g, Engine::SensorList* list, QVector<WidgetLookup> *lookup) {

        for (std::list<const Sensor::AbstractSensor*>::const_iterator it = list->begin(); it != list->end(); ++it) {
            (*it)->accept(list_sensor);
            QWidget* widget = list_sensor.getWidget();
            g->addWidget(widget, g->rowCount(), 0);
            lookup->push_back(WidgetLookup(
                *it,
                widget, 
                list_sensor.getViewButton(), 
                list_sensor.getEditButton(), 
                list_sensor.getDeleteButton()
                ));
        }

    }
}
