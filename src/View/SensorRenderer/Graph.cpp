#include "Graph.h"

namespace View::GraphRenderer {

    void Graph::render(QGridLayout* grid , const Sensor::AbstractSensor* sensor, GraphLookup*& lookup) {

        sensor->accept(full);
        lookup = new GraphLookup(
                const_cast<Sensor::AbstractSensor*>(sensor),
                full.getWidget(),
                full.getId(),
                full.getName(),
                full.getDataNum(),
                full.getSimulateButton(),
                full.getEditButton(),
                full.getClearButton(),
                full.getChart(),
                full.getXAxis(),
                full.getYAxis(),
                full.getChartView()
                );

        QWidget* widget = full.getWidget();
        grid->addWidget(widget, 0, 0);

    }
}