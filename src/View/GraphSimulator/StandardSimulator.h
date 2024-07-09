#ifndef VIEW_GRAPH_RENDERER_STANDARD_SIMULATOR_H
#define VIEW_GRAPH_RENDERER_STANDARD_SIMULATOR_H

#include "SGraphSimulator.h"
#include "SimulationVisitor.h"
#include "Sensor/AbstractSensor.h"
#include "View/SensorWidget.h"


namespace View::GraphRenderer{

    class StandardSimulator : public SGraphSimulator{

        SimulationVisitor simulation_visitor;

    public:
        void simulate(Sensor::AbstractSensor* sensor, GraphLookup*& lookup) override;
    };

}

#endif // VIEW_GRAPH_RENDERER_STANDARD_SIMULATOR_H
