#include "Full.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <QGroupBox>
// #include <QChart>

#include "../../Sensor/Airqualitysensor.h"
#include "../../Sensor/Humiditysensor.h"
#include "../../Sensor/TemperatureSensor.h"


namespace View::SensorRenderer {

    Full::Full(){

    }

    void Full::visit(const Sensor::AirQualitySensor& air_quality){
        widget = new QWidget();
        QGridLayout* grid = new QGridLayout();

        name = new QLabel("Name: " + QString::fromStdString(air_quality.getName()));
        id = new QLabel("ID: " + QString::number(air_quality.getIdentifier()));
        data_num = new QLabel("Data Num: " + QString::number(air_quality.getDataNum()));
        variance = new QLabel("Variance: " + QString::number(air_quality.getVariance()));
        
        QLabel* initial_pm_10 = new QLabel("Initial PM10: " + QString::number(air_quality.getInitialPm10()));
        QLabel* initial_n02 = new QLabel("Initial NO2: " + QString::number(air_quality.getInitialNO2()));
        QLabel* std_dev_pm_10 = new QLabel("Standard Deviation PM10: " + QString::number(air_quality.getStdDeviationPm10()));
        QLabel* std_dev_n02 = new QLabel("Standard Deviation NO2: " + QString::number(air_quality.getStdDeviationNO2()));
        QLabel* target_pm_10 = new QLabel("Target PM10: " + QString::number(air_quality.getTargetPm10()));
        QLabel* target_n02 = new QLabel("Target NO2: " + QString::number(air_quality.getTargetNO2()));

        simulate_button = new QPushButton("Simulate");
        edit_button = new QPushButton("Edit");
        clear_button = new QPushButton("Clear"); 

        // QChart *chart = new QChart();
        // chart->legend()->hide();
        // chart->addSeries(series);
        // chart->createDefaultAxes();
        // chart->setTitle("Simple line chart example");

        grid->addWidget(name, 0, 0, 1, 0);
        grid->addWidget(id, 1, 0, 1, 0);
        grid->addWidget(data_num, 2, 0, 1, 0);
        grid->addWidget(variance, 3, 0, 1, 0);

        grid->addWidget(initial_pm_10, 0, 1, 1, 1);
        grid->addWidget(initial_n02, 1, 1, 1, 1);
        grid->addWidget(std_dev_pm_10, 2, 1, 1, 1);
        grid->addWidget(std_dev_n02, 3, 1, 1, 1);
        grid->addWidget(target_pm_10, 4, 1, 1, 1);
        grid->addWidget(target_n02, 5, 1, 1, 1);

        grid->addWidget(simulate_button, 0, 2, 1, 1);
        grid->addWidget(edit_button, 1, 2, 1, 1);
        grid->addWidget(clear_button, 2, 2, 1, 1);

        // grid->addWidget(chart, 6, 2, 3, 1);

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
    QLabel* Full::getDataName()const{
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


}
