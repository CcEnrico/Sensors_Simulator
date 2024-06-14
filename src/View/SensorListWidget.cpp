#include"SensorListWidget.h"
#include "ListRenderer/List.h"
#include "SensorWidget.h"
#include "Sensor/AbstractSensor.h"
#include "mainwindow.h"

#include <QScrollArea>
#include <QLabel>

#include <functional>
#include <typeinfo>

namespace View{

SensorListWidget::SensorListWidget(SensorWidget* s_w, QWidget* parent)
    : QWidget(parent),
    sensor_widget(s_w)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* lista = new QLabel("Lista Sensori");
    lista->setAlignment(Qt::AlignCenter);
    vbox->addWidget(lista);

    QHBoxLayout* sort_layout = new QHBoxLayout();
    QPushButton* sort_button_id = new QPushButton("Sort ID");
    sort_layout->addWidget(sort_button_id);
    QPushButton* sort_button_name = new QPushButton("Sort Name");
    sort_layout->addWidget(sort_button_name);
    QWidget* sort_container = new QWidget();
    sort_container->setLayout(sort_layout);
    vbox->addWidget(sort_container);

    layout = new QGridLayout();
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(layout);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);

    renderer = new ListRenderer::List();

//    connessioni
    connect(sort_button_id, &QPushButton::clicked, this, &SensorListWidget::sortId);
    connect(sort_button_name, &QPushButton::clicked, this, &SensorListWidget::sortName);

}

SensorListWidget::~SensorListWidget() {
    delete renderer;
}

void SensorListWidget::showList(Engine::SensorList* list, Sensor::Repository::JsonRepository* repository, Engine::SensorList* query ){

    clean();

    if(query != nullptr && !query->isEmpty() ){
        renderer->render(layout, query , &lookup);
    }else{
        renderer->render(layout, list , &lookup);
    }

    for (
        QVector<WidgetLookup>::const_iterator it = lookup.begin();
        it != lookup.end();
        it++
    ) {
        if (it->getViewButton()) {
            connect(it->getViewButton(), &QPushButton::clicked, this, [=]() {
                sensor_widget->show(it->getSensor());
            });
        }
        if (it->getEditButton()) {
             connect(it->getEditButton(), &QPushButton::clicked, [this, it]() {
                 editSensor(it);
             });
        }
        if (it->getDeleteButton()) {
             connect(it->getDeleteButton(), &QPushButton::clicked, [this, it, list, repository, query]() {
                 deleteSensor(it, list, repository, query);
             });
        }
    }
}

    void SensorListWidget::editSensor(QVector<WidgetLookup>::const_iterator it ){
        MainWindow* main = qobject_cast<MainWindow*>(this->parent()->parent()->parent());
        Sensor::AbstractSensor* s = const_cast<Sensor::AbstractSensor*> (it->getSensor());
        if (main != nullptr) {
            main->editItem(s);
        }
    }

    void SensorListWidget::deleteSensor(QVector<WidgetLookup>::const_iterator it, Engine::SensorList* list, Sensor::Repository::JsonRepository* repository, Engine::SensorList* query ){
        lookup.erase(it);
        if(repository != nullptr) repository->erase(it->getSensor()->getIdentifier());   // cancella dalla mappa
        if(query != nullptr && !query->isEmpty()) query->erase(it->getSensor()); // cancella dalla query se esiste
        list->erase(it->getSensor()); // cancella dalla lista

        // se il sensore che voglio cancellare non e' vuoto e è quello che è attualmente nel lookup del sensor widget
        // ovvero se il sensore che sto cancellando e' quello mostrato nel widget del grafo allora lo nascondo
        if ( !(sensor_widget->isEmpty()) && sensor_widget->getLookup()->getSensor()->getIdentifier() == it->getSensor()->getIdentifier() && !sensor_widget->isEmpty() ){
            sensor_widget->hideSensorWidget();
        }
        delete it->getSensor(); // Dealloca oggetto
        delete it->getWidget();
    }

    void SensorListWidget::clean(){
        while(!lookup.isEmpty()){
            WidgetLookup info = lookup.takeLast();
            delete info.getWidget();    // questo dealloca la memoria del widget
        }
    }

    void SensorListWidget::sortId() {
        emit sortId_event();
    }

    void SensorListWidget::sortName() {
        emit sortName_event();
    }
}
