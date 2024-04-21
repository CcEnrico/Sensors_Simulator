#ifndef VIEW_ITEM_RENDERER_FULL_H
#define VIEW_ITEM_RENDERER_FULL_H


#include "QtWidgets/QLabel"
#include "QtCharts/QChartView"
#include "View/SensorRenderer/ListSensor.h"
#include <QValueAxis>

namespace View::GraphRenderer {

class Full: public Sensor::SConstVisitor {
  private:
    QWidget* widget;
    QLabel* id;
    QLabel* name;
    QLabel* data_num;
    QLabel* variance;
    QPushButton* simulate_button;
    QPushButton* edit_button;
    QPushButton* clear_button;
    QChart* chart;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QChartView* view_chart;

  public:
    Full();
    void visit(const Sensor::AirQualitySensor& air_quality) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    virtual QWidget* getWidget() const;
    virtual QLabel* getId()const;
    virtual QLabel* getName()const;
    virtual QLabel* getDataNum()const;
    virtual QLabel* getVariance()const;
    virtual QPushButton* getSimulateButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getClearButton() const;
    virtual QChart* getChart() const;
    QValueAxis* getXAxis();
    QValueAxis* getYAxis();
    virtual QChartView* getChartView() const;
};

}


#endif