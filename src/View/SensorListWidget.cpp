#include"SensorListWidget.h"
#include "ListRenderer/List.h"
#include "SensorWidget.h"
#include "Sensor/AbstractSensor.h"

#include <QScrollArea>
#include <QLabel>
#include <functional>

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

void SensorListWidget::showList(Engine::SensorList* list){

    while(!lookup.isEmpty()){
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }

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
//                 editItem(it->getSensor());
             });
        }
        if (it->getDeleteButton()) {
             connect(it->getDeleteButton(), &QPushButton::clicked, [this, it, list]() {
                 deleteSensor(it, list);
             });
        }
    }
}

    void SensorListWidget::deleteSensor(QVector<WidgetLookup>::const_iterator it, Engine::SensorList* list ){
        lookup.erase(it);
        list->remove(it->getSensor());

        delete it->getWidget();

        // se il sensore che voglio cancellare è quello che è attualmente nel lookup del sensor widget
        if (sensor_widget->getLookup()->getSensor()->getIdentifier() == it->getSensor()->getIdentifier() && !sensor_widget->isEmpty() ){
            sensor_widget->hideSensorWidget();
        }

    }

}
