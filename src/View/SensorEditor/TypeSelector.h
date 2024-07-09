#ifndef VIEW_TYPE_SELECTOR_H
#define VIEW_TYPE_SELECTOR_H

#include "QtWidgets/QComboBox"

#include "Sensor/SConstVisitor.h"

namespace View {
    class TypeSelector: public Sensor::SConstVisitor {
      private:
        QComboBox* combo_box;

      public:
        explicit TypeSelector(QComboBox* combo_box);
        void visit(const Sensor::AirQualitySensor& air_quality) override;
        void visit(const Sensor::HumiditySensor& humidity) override;
        void visit(const Sensor::TemperatureSensor& temperature) override;
        QComboBox* getComboBox();
        TypeSelector& setComboBox(QComboBox* cb);
    };
}

#endif // VIEW_TYPE_SELECTOR_H