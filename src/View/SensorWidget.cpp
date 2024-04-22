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
        
        // QVBoxLayout* vbox = new QVBoxLayout(this);

        // QWidget* container = new QWidget();
        // QLabel* id = new QLabel("ID: ");
        // QLabel* name = new QLabel("Name:");
        // QLabel* data_name = new QLabel("Data Name:");
        // QLabel* variance = new QLabel("Variance:");
        // QPushButton* simulate_button = new QPushButton("Simulate");
        // QPushButton* edit_button = new QPushButton("Edit");
        // QPushButton* clear_button = new QPushButton("Clear");

        // vbox->addWidget(id);
        // vbox->addWidget(name);
        // vbox->addWidget(data_name);
        // vbox->addWidget(variance);
        // vbox->addWidget(simulate_button);
        // vbox->addWidget(edit_button);
        // vbox->addWidget(clear_button);

        // container->setLayout(vbox);

//         lookup = new GraphLookup(nullptr, container, id, name, data_name, variance, simulate_button, edit_button, clear_button);
        
    }

    void SensorWidget::show(const Sensor::AbstractSensor* sensor) {

        if (lookup != nullptr){
            delete lookup->getWidget();
        }

       renderer->render(layout , sensor, lookup);

        if (lookup->getSimulateButton()){
            QPushButton* button = lookup->getSimulateButton();
            connect(button, &QPushButton::clicked, this, &SensorWidget::simulate );
        }
        if (lookup->getClearButton()){
            QPushButton* button = lookup->getClearButton();
            connect(button, &QPushButton::clicked, this, &SensorWidget::clear );
        }


    }

    void SensorWidget::clearChart() {
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

}