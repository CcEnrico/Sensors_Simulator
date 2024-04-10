#ifndef VIEW_SENSOR_WIDGET_H
#define VIEW_SENSOR_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "GraphLookup.h"
#include "GraphRenderer/SGraphRenderer.h"

namespace View{

    class SensorWidget : public QWidget {

        Q_OBJECT

        GraphLookup* lookup;
        QGridLayout* layout;
        GraphRenderer::SGraphRenderer* renderer;

    public:
        explicit SensorWidget(QWidget* parent = nullptr);

        void show(const Sensor::AbstractSensor* sensor);

    };
}

#endif //VIEW_SENSOR_WIDGET_H
