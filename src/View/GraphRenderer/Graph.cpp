#include "Graph.h"

namespace View::GraphRenderer {

    void Graph::render(QGridLayout* grid , const Sensor::AbstractSensor* sensor, GraphLookup* lookup) {

        sensor->accept(full);


        QWidget* widget = full.getWidget();
        widget->show();
        grid->addWidget(widget, 0, 0);
        lookup = new GraphLookup(
               sensor,
               widget,
               full.getId(),
               full.getName(),
               full.getDataName(),
               full.getVariance(),
               full.getSimulateButton(),
               full.getEditButton(),
               full.getSimulateButton()
               );
    }
}