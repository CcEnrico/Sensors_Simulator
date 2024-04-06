#ifndef VIEW_TYPE_SELECTOR_H
#define VIEW_TYPE_SELECTOR_H

#include <QComboBox>

#include "../Sensor/SConstVisitor.h"

namespace View {

class TypeSelector: public Sensor::SConstVisitor {
  private:
    QComboBox* combo_box;
  
  public:
    TypeSelector(QComboBox* combo_box);
    virtual void visit(const Sensor::AirQualitySensor& air_quality);
    virtual void visit(const Sensor::HumiditySensor& humidity);
    virtual void visit(const Sensor::TemperatureSensor& temperature);
    QComboBox* getComboBox();
    TypeSelector& setComboBox(QComboBox* combo_box);
};

}

#endif