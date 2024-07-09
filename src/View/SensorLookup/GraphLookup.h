#ifndef VIEW_GRAPH_LOOKUP_H
#define VIEW_GRAPH_LOOKUP_H

#include "QtWidgets/QWidget"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QLabel"
#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QValueAxis"

#include "Sensor/AbstractSensor.h"

namespace View {

    class GraphLookup {
    private:
        Sensor::AbstractSensor* sensor;
        QWidget* widget;

        QLabel* id;
        QLabel* name;
        QLabel* data_name;
        QPushButton* simulate_button;
        QPushButton* edit_button;
        QPushButton* clear_button;
        QChart* chart;
        QValueAxis* axisX;
        QValueAxis* axisY;
        QChartView* view_chart;

    public:
        GraphLookup(
                Sensor::AbstractSensor* sensor,
                QWidget* widget,
                QLabel* id,
                QLabel* name,
                QLabel* data_name,
                QPushButton* simulate_button,
                QPushButton* edit_button,
                QPushButton* clear_button,
                QChart* chart,
                QValueAxis* axisX,
                QValueAxis* axisY,
                QChartView* view_chart
        );

        Sensor::AbstractSensor* getSensor() const;
        QWidget* getWidget() const;
        GraphLookup& setWidget(QWidget* w);
        QLabel* getId()const;
        QLabel* getName()const;
        QLabel* getDataName()const;
        QPushButton* getSimulateButton() const;
        QPushButton* getEditButton() const;
        QPushButton* getClearButton() const;
        QChart* getChart() const;
        QValueAxis* getXAxis();
        QValueAxis* getYAxis();
        QChartView* getChartView() const;
    };

}

#endif //VIEW_GRAPH_LOOKUP_H
