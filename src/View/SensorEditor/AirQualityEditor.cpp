#include"AirQualityEditor.h"

#include <QFormLayout>

#include "../../Sensor/Airqualitysensor.h"

namespace View {
namespace SensorEditor {

AirQualityEditor::AirQualityEditor(QWidget* parent)
    : AbstractSensorEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("AirQualityEditorForm");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QDoubleSpinBox* initial = new QDoubleSpinBox();
    initial->setObjectName("Initial");
    form->addRow("Initial", initial);

    QDoubleSpinBox* stdDeviation = new QDoubleSpinBox();
    stdDeviation->setObjectName("StdDeviation");
    form->addRow("Standard Deviation", stdDeviation);

    QDoubleSpinBox* target = new QDoubleSpinBox();
    target->setObjectName("Target");
    form->addRow("Target", target);

}

AirQualityEditor::~AirQualityEditor() {
}

Sensor::AbstractSensor* AirQualityEditor::create(
    const unsigned int i,
    const QString& n,
    const unsigned int dn,
    const double v

) const {
    return new Sensor::AirQualitySensor(
        i,
        n.toStdString(),
        dn,
        v,
        initial->value(),
        stdDeviation->value(),
        target->value()
    );
}


void AirQualityEditor::setValues(const Sensor::AirQualitySensor& air_quality_sensor) {
    initial->setValue(double(air_quality_sensor.getAQInitial()));
    stdDeviation->setValue(double(air_quality_sensor.getAQStdDeviation()));
    target->setValue(double(air_quality_sensor.getAQTarget()));
}

}
}