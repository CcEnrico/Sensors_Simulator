#ifndef VIEW_WIDGET_LOOKUP_H
#define VIEW_WIDGET_LOOKUP_H

#include <QWidget>
#include <QPushButton>

#include "../Sensor/AbstractSensor.h"

namespace View {

class WidgetLookup {
  private:
    const Sensor::AbstractSensor* sensor;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    WidgetLookup(
        const Sensor::AbstractSensor* sensor,
        QWidget* widget,
        QPushButton* view_button,
        QPushButton* edit_button,
        QPushButton* delete_button
    );
    const Sensor::AbstractSensor* getSensor() const;
    QWidget* getWidget() const;
    QPushButton* getViewButton() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
};

}

#endif