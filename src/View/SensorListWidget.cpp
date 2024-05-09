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
    vbox->addWidget(lista);

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

}

void SensorListWidget::showList(Engine::SensorList* list, Sensor::Repository::JsonRepository* repository){

    clean();

    renderer->render(layout, list , &lookup);

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
             connect(it->getDeleteButton(), &QPushButton::clicked, [this, it, list, repository]() {
                 deleteSensor(it, list, repository);
             });
        }
    }
}

    void SensorListWidget::editSensor(QVector<WidgetLookup>::const_iterator it ){
        MainWindow* main = qobject_cast<MainWindow*>(this->parent()->parent());
        Sensor::AbstractSensor* s = const_cast<Sensor::AbstractSensor*> (it->getSensor());
        if (main != nullptr) {
            main->editItem(s);
        }
        // controllo di tipo sugli oggetti genitori parent è Qsplitter :) ;
//        std::cout << "Type of object: " << typeid( *(this->parent()->parent() ) ).name() << std::endl;

    }

    void SensorListWidget::deleteSensor(QVector<WidgetLookup>::const_iterator it, Engine::SensorList* list, Sensor::Repository::JsonRepository* repository ){
        lookup.erase(it);
        if(repository != nullptr) repository->erase(it->getSensor()->getIdentifier());   // cancella dalla mappa
        list->erase(it->getSensor()); // cancella dalla lista

        // se il sensore che voglio cancellare non e' vuoto e è quello che è attualmente nel lookup del sensor widget
        // ovvero se il sensore che sto cancellando e' quello mostrato nell widget del grafo allora lo nascondo
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



}
