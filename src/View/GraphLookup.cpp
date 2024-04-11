#include "GraphLookup.h"

#include <QWidget>
#include <QPushButton>

namespace View{
    GraphLookup::GraphLookup(const Sensor::AbstractSensor* s,
            QWidget* w,
            QLabel* i,
            QLabel* n,
            QLabel* d,
            QLabel* v,
            QPushButton* simu,
            QPushButton* edit,
            QPushButton* clear
    ):sensor(s),
    widget(w),
    id(i),
    name(n),
    data_name(d),
    variance(v),
    simulate_button(simu),
    edit_button(edit),
    clear_button(clear)
    {}

    const Sensor::AbstractSensor* GraphLookup::getSensor() const{
        return sensor;
    }
    QWidget* GraphLookup::getWidget() const{
        return widget;
    }

    GraphLookup& GraphLookup::setWidget(QWidget* w){
        this->widget = w;
        return *this;
    }

    QLabel* GraphLookup::getId()const{
        return id;
    }
    QLabel* GraphLookup::getName()const{
        return name;
    }
    QLabel* GraphLookup::getDataName()const{
        return data_name;
    }
    QLabel* GraphLookup::getVariance()const{
        return variance;
    }
    QPushButton* GraphLookup::getSimulateButton() const{
        return simulate_button;
    }
    QPushButton* GraphLookup::getEditButton() const{
        return edit_button;
    }
    QPushButton* GraphLookup::getClearButton() const{
        return clear_button;
    }

}