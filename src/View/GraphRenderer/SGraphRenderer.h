#ifndef VIEW_GRAPH_RENDERER_SGRAPH_RENDERER_H
#define VIEW_GRAPH_RENDERER_SGRAPH_RENDERER_H

#include "../../Sensor/AbstractSensor.h"
#include "../GraphLookup.h"
#include <QGridLayout>

namespace View::GraphRenderer {

    class SGraphRenderer{

    public:
        virtual ~SGraphRenderer() = default;
        virtual void render(QGridLayout* grid, const Sensor::AbstractSensor* sensor, GraphLookup*& lookup) = 0;

    };

}

#endif // VIEW_GRAPH_RENDERER_SGRAPH_RENDERER_H
