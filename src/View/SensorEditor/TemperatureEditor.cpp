#include"TemperatureEditor.h"

#include <QFormLayout>

namespace View{
namespace SensorEditor{

TemperatureEditor::TemperatureEditor(QWidget* parent)
    : AbstractSensorEditor(parent)
{
    // Default unit is Celsius 
    unit_char = 'c';

    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("TemperatureEditorForm");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    unit = new QComboBox(this);
    unit->addItem("Celsius");
    unit->addItem("Fahrenheit");
    unit->addItem("Kelvin");
    

    min = new QDoubleSpinBox();
    min->setObjectName("Min");
    min->setSuffix("°C");
    min->setMinimum(-273.15);
    min->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Min ", min);

    max = new QDoubleSpinBox();
    max->setObjectName("Max");
    max->setSuffix("°C");
    min->setMinimum(-273.15);
    max->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Max ", max);

    initial = new QDoubleSpinBox();
    initial->setObjectName("Initial");
    initial->setSuffix("°C");
    initial->setMinimum(-273.15);

    form->addRow("Initial ", initial);

    stdDeviation = new QDoubleSpinBox();
    stdDeviation->setObjectName("Standard Deviation");
    stdDeviation->setSuffix("°C");
    stdDeviation->setMinimum(-273.15);
    stdDeviation->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Standard Deviation ", stdDeviation);

    target = new QDoubleSpinBox();
    target->setObjectName("Target");
    target->setSuffix("°C");
    target->setMinimum(-273.15);
    target->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Target ", target);

    connect(unit, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TemperatureEditor::unitChanged);

}

TemperatureEditor::~TemperatureEditor() {}

Sensor::AbstractSensor* TemperatureEditor::create(
    const unsigned int i,
    const QString& n,
    const unsigned int dn,
    const double v
) const {
    return new Sensor::TemperatureSensor(
        i,
        n.toStdString(),
        dn,
        v,
        Sensor::EnviromentalConditions::Temperature(min->value(), unit_char),
        Sensor::EnviromentalConditions::Temperature(max->value(), unit_char),
        Sensor::EnviromentalConditions::Temperature(initial->value(), unit_char),
        Sensor::EnviromentalConditions::Temperature(stdDeviation->value(), unit_char),
        Sensor::EnviromentalConditions::Temperature(target->value(), unit_char)
    ); 
}

void TemperatureEditor::setValues(const Sensor::TemperatureSensor& temperature_sensor){
    // Default unit is Celsius = 0
    unit->setCurrentIndex(0);
    unitChanged(0);
    min->setValue(double(temperature_sensor.getTempMin()));
    max->setValue(double(temperature_sensor.getTempMax()));
    initial->setValue(double(temperature_sensor.getTempInitial()));
    stdDeviation->setValue(double(temperature_sensor.getStdDeviation()));
    target->setValue(double(temperature_sensor.getTempTarget()));
}

void TemperatureEditor::unitChanged(int index){
    // index 0 = Celsius
    // index 1 = Fahrenheit
    // index 2 = Kelvin

    if(index == 0){
        min->setSuffix("°C");
        max->setSuffix("°C");
        initial->setSuffix("°C");
        stdDeviation->setSuffix("°C");
        target->setSuffix("°C");
        unit_char = 'c';

        min->setMinimum(-273.15);
        max->setMinimum(-273.15);
        initial->setMinimum(-273.15);
        stdDeviation->setMinimum(-273.15);
        target->setMinimum(-273.15);

    }else if(index == 1){
        min->setSuffix("°F");
        max->setSuffix("°F");
        initial->setSuffix("°F");
        stdDeviation->setSuffix("°F");
        target->setSuffix("°F");

        unit_char = 'f';

        min->setMinimum(-459.67);
        max->setMinimum(-459.67);
        initial->setMinimum(-459.67);
        stdDeviation->setMinimum(-459.67);
        target->setMinimum(-459.67);

    }else if(index == 2){
        min->setSuffix("K");
        max->setSuffix("K");
        initial->setSuffix("K");
        stdDeviation->setSuffix("K");
        target->setSuffix("K");

        unit_char = 'k';

        min->setMinimum(0);
        max->setMinimum(0);
        initial->setMinimum(0);
        stdDeviation->setMinimum(0);
        target->setMinimum(0);
    }

}

}
}