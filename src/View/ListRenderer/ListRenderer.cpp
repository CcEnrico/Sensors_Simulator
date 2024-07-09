#include "ListRenderer.h"

#include "QtWidgets/QLabel"
#include "QtWidgets/QGridLayout"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QPushButton"

#include "Sensor/Airqualitysensor.h"
#include "Sensor/Humiditysensor.h"
#include "Sensor/TemperatureSensor.h"

namespace View::SensorRenderer {

ListRenderer::ListRenderer()
    : has_controls(true)
{
}

void ListRenderer::visit(const Sensor::AirQualitySensor& air_quality){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* name = new QLabel("Name: " + QString::fromStdString(air_quality.getName()));
    QLabel* id = new QLabel("ID: " + QString::number(air_quality.getIdentifier()));

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Assets/icons/air-quality.svg").pixmap(70,70));

    view_button = new QPushButton(QIcon(":/Assets/icons/search.svg"),"");
    edit_button = new QPushButton(QIcon(":/Assets/icons/edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Assets/icons/delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);

    grid->addWidget(icon, 0, 0, 4, 1); 
    grid->addWidget(name, 0, 1, 1, 1);  
    grid->addWidget(id, 1, 1, 1, 1);   
    grid->addWidget(button_container, 2, 1, 2, 1);  

    widget->setLayout(grid);
}

void ListRenderer::visit(const Sensor::HumiditySensor& humidity){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* name = new QLabel("Name: " + QString::fromStdString(humidity.getName()));
    QLabel* id = new QLabel("ID: " + QString::number(humidity.getIdentifier()));

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Assets/icons/humidity.svg").pixmap(70,70));

    view_button = new QPushButton(QIcon(":/Assets/icons/search.svg"),"");
    edit_button = new QPushButton(QIcon(":/Assets/icons/edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Assets/icons/delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);

    grid->addWidget(icon, 0, 0, 4, 1); 
    grid->addWidget(name, 0, 1, 1, 1);  
    grid->addWidget(id, 1, 1, 1, 1);   
    grid->addWidget(button_container, 2, 1, 2, 1);

    widget->setLayout(grid);
}

void ListRenderer::visit(const Sensor::TemperatureSensor& temperature){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* name = new QLabel("Name: " + QString::fromStdString(temperature.getName()));
    QLabel* id = new QLabel("ID: " + QString::number(temperature.getIdentifier()));

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Assets/icons/temperature.svg").pixmap(70,70));

    view_button = new QPushButton(QIcon(":/Assets/icons/search.svg"),"");
    edit_button = new QPushButton(QIcon(":/Assets/icons/edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Assets/icons/delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);

    grid->addWidget(icon, 0, 0, 4, 1); 
    grid->addWidget(name, 0, 1, 1, 1);  
    grid->addWidget(id, 1, 1, 1, 1);   
    grid->addWidget(button_container, 2, 1, 2, 1);  

    widget->setLayout(grid);
}

bool ListRenderer::hasControls() const{
    return has_controls;
}

void ListRenderer::setHasControls(const bool c){
    this->has_controls = c;
}

QWidget* ListRenderer::getWidget() const{
    return widget;
}

QPushButton* ListRenderer::getViewButton() const{
    return view_button;
}

QPushButton* ListRenderer::getEditButton() const{
    return edit_button;
}

QPushButton* ListRenderer::getDeleteButton() const{
    return delete_button;
}

}