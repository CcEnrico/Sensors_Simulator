#ifndef VIEW_GRAPH_LOOKUP_H
#define VIEW_GRAPH_LOOKUP_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include "../Sensor/AbstractSensor.h"

namespace View {

    class GraphLookup {
    private:
        const Sensor::AbstractSensor* sensor;
        QWidget* widget;

        QLabel* id;
        QLabel* name;
        QLabel* data_name;
        QLabel* variance;
        QPushButton* simulate_button;
        QPushButton* edit_button;
        QPushButton* clear_button;

    public:
        GraphLookup(
                const Sensor::AbstractSensor* sensor,
                QWidget* widget,
                QLabel* id,
                QLabel* name,
                QLabel* data_name,
                QLabel* variance,
                QPushButton* simulate_button,
                QPushButton* edit_button,
                QPushButton* clear_button
        );
        const Sensor::AbstractSensor* getSensor() const;
        QWidget* getWidget() const;
        GraphLookup& setWidget(QWidget* w);
        QLabel* getId()const;
        QLabel* getName()const;
        QLabel* getDataName()const;
        QLabel* getVariance()const;
        QPushButton* getSimulateButton() const;
        QPushButton* getEditButton() const;
        QPushButton* getClearButton() const;
    };

}

#endif //VIEW_GRAPH_LOOKUP_H
