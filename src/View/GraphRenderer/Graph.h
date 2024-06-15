#ifndef VIEW_GRAPH_RENDERER_GRAPH_H
#define VIEW_GRAPH_RENDERER_GRAPH_H

#include "SGraphRenderer.h"
#include "Full.h"
#include "../SensorWidget.h"
#include "../../Sensor/AbstractSensor.h"

namespace View::GraphRenderer{

    class Graph : public SGraphRenderer{

        Full full;

    public:

        void render(QGridLayout* grid, const Sensor::AbstractSensor* sensor, GraphLookup*& lookup) override;

    };
}

#endif // VIEW_GRAPH_RENDERER_GRAPH_H
