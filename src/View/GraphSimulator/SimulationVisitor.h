#ifndef VIEW_GRAPH_RENDERER_SIMULATION_VISITOR_H
#define VIEW_GRAPH_RENDERER_SIMULATION_VISITOR_H

#include "Sensor/SVisitor.h"

#include "QtWidgets/QWidget"
#include "QtWidgets/QLabel"
#include "QtWidgets/QPushButton"
#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QValueAxis"

namespace View::GraphRenderer{

    class SimulationVisitor : public Sensor::SVisitor {
    private:
        QChart* chart;
        QValueAxis *axisX;
        QValueAxis *axisY;
        QChartView* view_chart;

    public:
        SimulationVisitor();
        void visit(Sensor::AirQualitySensor& air_quality) override;
        void visit(Sensor::HumiditySensor& humidity) override;
        void visit(Sensor::TemperatureSensor& temperature) override;

        virtual QChart* getChart() const;
        SimulationVisitor& setChart(QChart* chart);

        QValueAxis* getXAxis() const;
        SimulationVisitor& setXAxis(QValueAxis* x);
        QValueAxis* getYAxis() const;
        SimulationVisitor& setYAxis(QValueAxis* y);

        virtual QChartView* getChartView() const;
        SimulationVisitor& setChartView(QChartView* view_chart);
    };
}

#endif // VIEW_GRAPH_RENDERER_SIMULATION_VISITOR_H
