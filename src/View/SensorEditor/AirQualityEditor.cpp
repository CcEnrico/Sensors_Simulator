#include"AirQualityEditor.h"

#include <QFormLayout>

#include "../../Sensor/Airqualitysensor.h"
#include "../../Sensor/EnvironmentalConditions/Airquality.h"


namespace View::SensorEditor {

AirQualityEditor::AirQualityEditor(QWidget* parent)
    : AbstractSensorEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("AirQualityEditorForm");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    initial_pm10 = new QDoubleSpinBox();
    initial_pm10->setObjectName("Initial Pm10 ");
    initial_pm10->setMinimum(0);
    initial_pm10->setDecimals(14);
    initial_pm10->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Initial Pm10 micro_g/m3 ", initial_pm10);

    initial_n02 = new QDoubleSpinBox();
    initial_n02->setObjectName("Initial NO2 ");
    initial_n02->setMinimum(0);
    initial_n02->setDecimals(14);
    initial_n02->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Initial NO2 micro_g/m3 ", initial_n02);

    stdDeviation_pm10 = new QDoubleSpinBox();
    stdDeviation_pm10->setObjectName("Standard Deviation Pm10");
    stdDeviation_pm10->setMinimum(0);
    stdDeviation_pm10->setDecimals(14);
    stdDeviation_pm10->setMaximum(std::numeric_limits<double>::max());
    stdDeviation_pm10->setValue(5.0);
    form->addRow("Standard Deviation Pm10 micro_g/m3 ", stdDeviation_pm10);

    stdDeviation_n02 = new QDoubleSpinBox();
    stdDeviation_n02->setObjectName("Standard Deviation NO2");
    stdDeviation_n02->setMinimum(0);
    stdDeviation_n02->setDecimals(14);
    stdDeviation_n02->setMaximum(std::numeric_limits<double>::max());
    stdDeviation_n02->setValue(5.0);
    form->addRow("Standard Deviation NO2 micro_g/m3 ", stdDeviation_n02);

}

AirQualityEditor::~AirQualityEditor() = default;

Sensor::AbstractSensor* AirQualityEditor::create(
    const unsigned int i,
    const QString& n,
    const unsigned int dn

) const {
    return new Sensor::AirQualitySensor(
        i,
        n.toStdString(),
        dn,
        Sensor::EnviromentalConditions::AirQuality(initial_pm10->value(), initial_n02->value()),
        Sensor::EnviromentalConditions::AirQuality(stdDeviation_pm10->value(), stdDeviation_n02->value())
    );
}

void AirQualityEditor::setValues(const Sensor::AirQualitySensor& air_quality_sensor) {
    initial_pm10->setValue((air_quality_sensor.getInitialPm10()));
    initial_n02->setValue((air_quality_sensor.getInitialNO2()));
    stdDeviation_pm10->setValue((air_quality_sensor.getStdDeviationPm10()));
    stdDeviation_n02->setValue((air_quality_sensor.getStdDeviationNO2()));
}

}
