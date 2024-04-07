#include"HumidityEditor.h"
#include"AbstractSensorEditor.h"

#include <QFormLayout>

namespace View{
namespace SensorEditor{

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
    form->addRow("Standard Deviation Humidity ", stdDeviation);

    target = new QDoubleSpinBox();
    target->setObjectName("Target Humidity");
    target->setSuffix("%");
    target->setRange(0, 100);
    form->addRow("Target Humidity ", target);   
 
}

HumidityEditor::~HumidityEditor() {}

Sensor::AbstractSensor* HumidityEditor::create(
    const unsigned int i,
    const QString& n,
    const unsigned int dn,
    const double v
) const {
    return new Sensor::HumiditySensor(
        i,
        n.toStdString(),
        dn,
        v,
        initial->value(),
        stdDeviation->value(),
        target->value()
    );
}

void HumidityEditor::setValues(const Sensor::HumiditySensor& humidity_sensor){
    initial->setValue(double(humidity_sensor.getHumInitial()));
    stdDeviation->setValue(double(humidity_sensor.getHumStdDeviation()));
    target->setValue(double(humidity_sensor.getHumTarget()));
}

}
}