#ifndef VIEW_GRAPH_SENDERER_SGRAPH_SIMULATOR_H
#define VIEW_GRAPH_SENDERER_SGRAPH_SIMULATOR_H

#include "Sensor/AbstractSensor.h"
#include "View/SensorLookup/GraphLookup.h"

namespace View::GraphRenderer{

    class SGraphSimulator  {
    public:
        virtual ~SGraphSimulator() = default;
        virtual void simulate(Sensor::AbstractSensor* sensor, GraphLookup*& lookup) = 0;
    };

}

#endif //VIEW_GRAPH_SENDERER_SGRAPH_SIMULATOR_H
