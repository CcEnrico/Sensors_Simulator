#include "Graph.h"

namespace View::GraphRenderer {

    void Graph::render(QGridLayout* grid , const Sensor::AbstractSensor* sensor, GraphLookup* lookup) {

        if (full.getWidget() != nullptr) delete full.getWidget();

        sensor->accept(full);
        GraphLookup* item = new GraphLookup(
                sensor,
                full.getWidget(),
                full.getId(),
                full.getName(),
                full.getDataNum(),
                full.getVariance(),
                full.getSimulateButton(),
                full.getEditButton(),
                full.getClearButton()
                );
        lookup = item;
        QWidget* widget = full.getWidget();
        grid->addWidget(widget, 0, 0);

    }
}