#include "SimulationVisitor.h"

#include "Sensor/Airqualitysensor.h"
#include "Sensor/Humiditysensor.h"
#include "Sensor/TemperatureSensor.h"

#include <iostream>
#include <vector>
#include <QLineSeries>



namespace View::GraphRenderer{

    SimulationVisitor::SimulationVisitor() {}

    void SimulationVisitor::visit(Sensor::AirQualitySensor& air_quality) {

        air_quality.clear();
        air_quality.simulate();

        chart->removeAllSeries();
//        chart->createDefaultAxes();

        std::vector<double> pm10_data = air_quality.getAQDataPm10();
        std::vector<double> n02_data = air_quality.getAQDataN02();

        double max = 0;
        unsigned int it_max;

        QLineSeries* series_pm10 = new QLineSeries();
        unsigned int i = 0;
        for (auto it = pm10_data.begin(); it != pm10_data.end(); ++it) {
            series_pm10->append(i, *it);
            if (max < *it) max = *it;
            i++;
        }

        QLineSeries* series_n02 = new QLineSeries();
        unsigned int j = 0;
        for (auto it = n02_data.begin(); it != n02_data.end(); ++it) {
            series_n02->append(j, *it);
            if (max < *it) max = *it;
            j++;
        }
        if(i > j) it_max = i;
        else{it_max = j; }

        chart->addSeries(series_pm10);
        chart->addSeries(series_n02);

        series_pm10->setName("PM10 micro_g/m3");
        series_n02->setName("NO2 micro_g/m3");

        // Assi
        axisY->setTitleText("Air Quality");

        axisX->setRange(0, air_quality.getDataNum());
        axisY->setRange(0, max);
        

        QLineSeries* horizontalLineSeries = new QLineSeries();
        horizontalLineSeries->append(0, 50); // Starting point
        horizontalLineSeries->append(air_quality.getDataNum(), 50); // Ending point
        chart->addSeries(horizontalLineSeries);


        // Add legend
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);



    }
    void SimulationVisitor::visit(Sensor::HumiditySensor& humidity) {

    }
    void SimulationVisitor::visit(Sensor::TemperatureSensor& temperature) {

    }

    QChart* SimulationVisitor::getChart() const{
        return chart;
    }

    SimulationVisitor& SimulationVisitor::setChart(QChart* chart){
        this->chart = chart;
        return *this;
    }

    QValueAxis* SimulationVisitor::getXAxis() const{
        return axisX;
    }
    SimulationVisitor& SimulationVisitor::setXAxis(QValueAxis* x){
        this->axisX = x;
        return *this;
    }
    QValueAxis* SimulationVisitor::getYAxis() const{
        return axisY;
    }
    SimulationVisitor& SimulationVisitor::setYAxis(QValueAxis* y){
        this->axisY = y;
        return *this;
    }

    QChartView* SimulationVisitor::getChartView() const {
        return view_chart;
    }

    SimulationVisitor& SimulationVisitor::setChartView(QChartView* view_chart){
        this->view_chart = view_chart;
        return *this;
    }

}