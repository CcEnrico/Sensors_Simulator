#include"HumidityEditor.h"
#include"AbstractSensorEditor.h"

#include <QFormLayout>


namespace View::SensorEditor{

HumidityEditor::HumidityEditor(QWidget* parent)
    :AbstractSensorEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("HumidityEditorForm");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    initial = new QDoubleSpinBox();
    initial->setObjectName("Initial Humidity");
    initial->setSuffix("%");
    initial->setRange(0, 100);
    form->addRow("Initial Humidity ", initial);

    stdDeviation = new QDoubleSpinBox();
    stdDeviation->setObjectName("Standard Deviation Humidity");
    stdDeviation->setSuffix("%");
    stdDeviation->setRange(0, 100);
    stdDeviation->setValue(1.0);
    form->addRow("Standard Deviation Humidity ", stdDeviation);

    rain_probability = new QDoubleSpinBox();
    rain_probability->setObjectName("Rain Probability");
    rain_probability->setSuffix("%");
    rain_probability->setRange(0, 100);
    rain_probability->setValue(1.0);
    form->addRow("Rain Probability ", rain_probability);
 
}

HumidityEditor::~HumidityEditor() = default;

Sensor::AbstractSensor* HumidityEditor::create(
    const unsigned int i,
    const QString& n,
    const unsigned int dn
) const {
    return new Sensor::HumiditySensor(
        i,
        n.toStdString(),
        dn,
        Sensor::EnviromentalConditions::Humidity(initial->value()),
        Sensor::EnviromentalConditions::Humidity(stdDeviation->value()),
        rain_probability->value()
    );
}

void HumidityEditor::setValues(const Sensor::HumiditySensor& humidity_sensor){
    initial->setValue(double(humidity_sensor.getHumInitial()));
    stdDeviation->setValue(double(humidity_sensor.getHumStdDeviation()));
    rain_probability->setValue(humidity_sensor.getRainProbability());
}

}
