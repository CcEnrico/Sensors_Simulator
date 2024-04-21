#include "Full.h"

#include "QtWidgets/QLabel"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QHBoxLayout"
#include "QtGui/QPixmap"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QGroupBox"

#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QLineSeries"

#include "Sensor/Airqualitysensor.h"
#include "Sensor/Humiditysensor.h"
#include "Sensor/TemperatureSensor.h"


namespace View::GraphRenderer {

    Full::Full(){
    }

    void Full::visit(const Sensor::AirQualitySensor& air_quality){
        widget = new QWidget();
        QGridLayout* grid = new QGridLayout();

        QWidget* first = new QWidget();
        QVBoxLayout* first_column = new QVBoxLayout();
        QLabel* type = new QLabel("AIR QUALITY SENSOR");
        name = new QLabel("Name: " + QString::fromStdString(air_quality.getName()));
        id = new QLabel("ID: " + QString::number(air_quality.getIdentifier()));
        data_num = new QLabel("Data Num: " + QString::number(air_quality.getDataNum()));
        variance = new QLabel("Variance: " + QString::number(air_quality.getVariance()));
        first_column->addWidget(type);
        first_column->addWidget(name);
        first_column->addWidget(id);
        first_column->addWidget(data_num);
        first_column->addWidget(variance);
        first->setLayout(first_column);


        QWidget* second = new QWidget();
        QVBoxLayout* second_column = new QVBoxLayout();
        QLabel* initial_pm_10 = new QLabel("Initial PM10: " + QString::number(air_quality.getInitialPm10()));
        QLabel* initial_n02 = new QLabel("Initial NO2: " + QString::number(air_quality.getInitialNO2()));
        QLabel* std_dev_pm_10 = new QLabel("Standard Deviation PM10: " + QString::number(air_quality.getStdDeviationPm10()));
        QLabel* std_dev_n02 = new QLabel("Standard Deviation NO2: " + QString::number(air_quality.getStdDeviationNO2()));
        QLabel* target_pm_10 = new QLabel("Target PM10: " + QString::number(air_quality.getTargetPm10()));
        QLabel* target_n02 = new QLabel("Target NO2: " + QString::number(air_quality.getTargetNO2()));
        second_column->addWidget(initial_pm_10);
        second_column->addWidget(initial_n02);
        second_column->addWidget(std_dev_pm_10);
        second_column->addWidget(std_dev_n02);
        second_column->addWidget(target_pm_10);
        second_column->addWidget(target_n02);
        second->setLayout(second_column);

        QWidget* third = new QWidget();
        QVBoxLayout* third_column = new QVBoxLayout();
        simulate_button = new QPushButton("Simulate");
        edit_button = new QPushButton("Edit");
        clear_button = new QPushButton("Clear"); 
        third_column->addWidget(simulate_button);
        third_column->addWidget(edit_button);
        third_column->addWidget(clear_button);
        third->setLayout(third_column);


        chart = new QChart();

        axisX = new QValueAxis();
        axisX->setTitleText("Data Num");
        axisX->setRange(0, 100);
        chart->addAxis(axisX, Qt::AlignBottom);
        axisY = new QValueAxis();
        axisY->setRange(0, 100);
        chart->addAxis(axisY, Qt::AlignLeft);

        view_chart = new QChartView(chart);
        view_chart->setRenderHint(QPainter::Antialiasing);


        grid->addWidget(first, 0, 0);
        grid->addWidget(second, 0, 1);
        grid->addWidget(third, 0, 2);
        grid->addWidget(view_chart, 1, 0, 1, 3);

        widget->setLayout(grid);
    }
    void Full::visit(const Sensor::HumiditySensor& humidity){

    }
    void Full::visit(const Sensor::TemperatureSensor& temperature){

    }

    QWidget* Full::getWidget() const{
        return widget;
    }
    QLabel* Full::getId()const{
        return id;
    }
    QLabel* Full::getName()const{
        return name;
    }
    QLabel* Full::getDataNum()const{
        return data_num;
    }
    QLabel* Full::getVariance()const{
        return variance;
    }
    QPushButton* Full::getSimulateButton() const{
        return simulate_button;
    }
    QPushButton* Full::getEditButton() const{
        return edit_button;
    }
    QPushButton* Full::getClearButton() const {
        return clear_button;
    }
    QChart* Full::getChart() const{
        return chart;
    }
    QValueAxis* Full::getXAxis(){
        return axisX;
    }
    QValueAxis* Full::getYAxis(){
        return axisY;
    }
    QChartView* Full::getChartView() const{
        return view_chart;
    }



}
