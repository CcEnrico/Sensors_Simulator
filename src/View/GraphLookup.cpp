#include "GraphLookup.h"

#include <QWidget>
#include <QPushButton>

namespace View{
    GraphLookup::GraphLookup(Sensor::AbstractSensor* s,
            QWidget* w,
            QLabel* i,
            QLabel* n,
            QLabel* d,
            QPushButton* simu,
            QPushButton* edit,
            QPushButton* clear,
            QChart* c,
            QValueAxis* x,
            QValueAxis* y,
            QChartView* vc

    )
    :sensor(s),
    widget(w),
    id(i),
    name(n),
    data_name(d),
    simulate_button(simu),
    edit_button(edit),
    clear_button(clear),
    chart(c),
    axisX(x),
    axisY(y),
    view_chart(vc)
    {}

    Sensor::AbstractSensor* GraphLookup::getSensor() const{
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
    QPushButton* GraphLookup::getSimulateButton() const{
        return simulate_button;
    }
    QPushButton* GraphLookup::getEditButton() const{
        return edit_button;
    }
    QPushButton* GraphLookup::getClearButton() const{
        return clear_button;
    }
    QChart* GraphLookup::getChart() const{
        return chart;
    }
    QValueAxis* GraphLookup::getXAxis(){
        return axisX;
    }
    QValueAxis* GraphLookup::getYAxis(){
        return axisY;
    }
    QChartView* GraphLookup::getChartView() const{
        return view_chart;
    }

}