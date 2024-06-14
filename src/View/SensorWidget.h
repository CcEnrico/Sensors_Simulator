#ifndef VIEW_SENSOR_WIDGET_H
#define VIEW_SENSOR_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "GraphLookup.h"
#include "GraphRenderer/SGraphRenderer.h"
#include "GraphRenderer/SGraphSimulator.h"

namespace View{

    class SensorWidget : public QWidget {

        Q_OBJECT;

    private:
        GraphLookup* lookup;
        QGridLayout* layout;
        GraphRenderer::SGraphRenderer* renderer;
        GraphRenderer::SGraphSimulator* simulator;

    public:
        explicit SensorWidget(QWidget* parent = nullptr);
        ~SensorWidget() override;

        GraphLookup* getLookup();

        bool isEmpty() const;

        void show(const Sensor::AbstractSensor* sensor);


        void clearChart();
        void hideSensorWidget();
        void clean();

    public slots:
        void simulate();
        void clear();
        void edit();

    };
}

#endif //VIEW_SENSOR_WIDGET_H
