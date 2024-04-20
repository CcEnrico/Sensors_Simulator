#include "Graph.h"

namespace View::GraphRenderer {

    void Graph::render(QGridLayout* grid , const Sensor::AbstractSensor* sensor, GraphLookup*& lookup) {

        sensor->accept(full);
        lookup = new GraphLookup(
                sensor,
                full.getWidget(),
                full.getId(),
                full.getName(),
                full.getDataNum(),
                full.getVariance(),
                full.getSimulateButton(),
                full.getEditButton(),
                full.getClearButton(),
                full.getChart(),
                full.getChartView()
                );
        QWidget* widget = full.getWidget();
        grid->addWidget(widget, 0, 0);

    }
}