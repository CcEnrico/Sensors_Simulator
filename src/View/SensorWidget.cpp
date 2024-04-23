#include "SensorWidget.h"
#include "GraphRenderer/Graph.h"
#include "GraphRenderer/StandardSimulator.h"


namespace View{

    SensorWidget::SensorWidget(QWidget* parent)
        : QWidget(parent),
        lookup()
    {
        renderer = new GraphRenderer::Graph();

        layout = new QGridLayout(this);

        simulator = new GraphRenderer::StandardSimulator();

    }

    void SensorWidget::show(const Sensor::AbstractSensor* sensor) {

        if (lookup != nullptr){
            delete lookup->getWidget();
        }

        renderer->render(layout , sensor, lookup);
        simulate();

        if (lookup->getSimulateButton()){
            QPushButton* button = lookup->getSimulateButton();
            connect(button, &QPushButton::clicked, this, &SensorWidget::simulate );
        }
        if (lookup->getClearButton()){
            QPushButton* button = lookup->getClearButton();
            connect(button, &QPushButton::clicked, this, &SensorWidget::clear );
        }
        if (lookup->getEditButton()){
            QPushButton* button = lookup->getEditButton();
            connect(button, &QPushButton::clicked, this, &SensorWidget::edit );
        }


    }

    void SensorWidget::clearChart() {
        lookup->getSensor()->clear();
        QChart* chart = lookup->getChart();

        QList<QAbstractSeries*> seriesList = chart->series();
        for (auto series : seriesList) {
            chart->removeSeries(series);
            delete series;
        }
        chart->legend()->markers().clear();
    }

    void SensorWidget::simulate() {
        clearChart();

        Sensor::AbstractSensor* sensor = lookup->getSensor();
        simulator->simulate(sensor, lookup);


    }

    void SensorWidget::clear(){
        clearChart();
    }

    void SensorWidget::edit(){

    }

}