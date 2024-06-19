#ifndef VIEW_SENSOR_WIDGET_H
#define VIEW_SENSOR_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "View/SensorLookup/GraphLookup.h"
#include "SensorRenderer/SGraphRenderer.h"
#include "View/GraphSimulator/SGraphSimulator.h"

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

    signals:
        void edit_event(Sensor::AbstractSensor* s);


    };
}

#endif //VIEW_SENSOR_WIDGET_H
