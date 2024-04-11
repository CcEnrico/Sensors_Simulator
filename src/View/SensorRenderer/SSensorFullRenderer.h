
#ifndef VIEW_SENSOR_RENDERER_SSENSOR_FULL_RENDERER_H
#define VIEW_SENSOR_RENDERER_SSENSOR_FULL_RENDERER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include "../../Sensor/SConstVisitor.h"


namespace View::SensorRenderer {

    class SSensorFullRenderer: public Sensor::SConstVisitor {
    public:
        virtual QWidget* getWidget() const = 0;
        virtual QLabel* getId()const;
        virtual QLabel* getName()const;
        virtual QLabel* getDataName()const;
        virtual QLabel* getVariance()const;
        virtual QPushButton* getSimulateButton() const = 0;
        virtual QPushButton* getEditButton() const = 0;
        virtual QPushButton* getClearButton() const = 0;
    };

}

#endif //VIEW_SENSOR_RENDERER_SSENSOR_FULL_RENDERER_H
