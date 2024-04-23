#include "StandardSimulator.h"

namespace View::GraphRenderer{

    void StandardSimulator::simulate(Sensor::AbstractSensor* sensor, View::GraphLookup *&lookup) {

        simulation_visitor.setChart(lookup->getChart());
        simulation_visitor.setXAxis(lookup->getXAxis());
        simulation_visitor.setYAxis(lookup->getYAxis());
        simulation_visitor.setChartView(lookup->getChartView());

        sensor->clear();
        sensor->simulate();

        sensor->accept(simulation_visitor);

    }

}