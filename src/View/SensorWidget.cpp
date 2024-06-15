#include "SensorWidget.h"
#include "GraphRenderer/Graph.h"
#include "View/GraphSimulator/StandardSimulator.h"
#include "mainwindow.h"


namespace View{

    SensorWidget::SensorWidget(QWidget* parent)
        : QWidget(parent),
        lookup()
    {
        renderer = new GraphRenderer::Graph();

        layout = new QGridLayout(this);

        simulator = new GraphRenderer::StandardSimulator();

    }

    SensorWidget::~SensorWidget() {
        delete renderer;
        delete simulator;
        delete lookup;
    }

    GraphLookup* SensorWidget::getLookup(){
        return lookup;
    }

    bool SensorWidget::isEmpty() const{
        return layout->isEmpty();
    }

    void SensorWidget::show(const Sensor::AbstractSensor* sensor) {

        clean();

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

    void SensorWidget::clean(){
        if (!isEmpty()){
            delete lookup->getWidget();
        }
    }


    void SensorWidget::edit(){
        MainWindow* main = qobject_cast<MainWindow*>(this->parent()->parent()->parent());
        if (main != nullptr) {
            main->editItem( lookup->getSensor() );
        }
    }

    void SensorWidget::hideSensorWidget(){
        lookup->getWidget()->setVisible(false);
    };

}