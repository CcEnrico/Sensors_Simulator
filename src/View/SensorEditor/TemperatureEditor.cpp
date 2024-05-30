#include"TemperatureEditor.h"

#include <QFormLayout>


namespace View::SensorEditor{

TemperatureEditor::TemperatureEditor(QWidget* parent)
    : AbstractSensorEditor(parent),
      min_temp(0, 'c'),
      max_temp(0, 'c'),
      initial_temp(0, 'c'),
      target_temp(0, 'c')
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
    min->setValue(-10.0);
    min->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Min ", min);

    max = new QDoubleSpinBox();
    max->setObjectName("Max");
    max->setSuffix("°C");
    min->setMinimum(-273.15);
    max->setValue(10.0);
    max->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Max ", max);

    initial = new QDoubleSpinBox();
    initial->setObjectName("Initial");
    initial->setSuffix("°C");
    initial->setMinimum(-273.15);
    initial->setMaximum(std::numeric_limits<double>::max());

    form->addRow("Initial ", initial);

    stdDeviation = new QDoubleSpinBox();
    stdDeviation->setObjectName("Standard Deviation");
    stdDeviation->setSuffix("°C");
    stdDeviation->setMinimum(0); // deviazione standard è positiva
    stdDeviation->setValue(0.5);
    stdDeviation->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Standard Deviation ", stdDeviation);

    target = new QDoubleSpinBox();
    target->setObjectName("Target");
    target->setSuffix("°C");
    target->setMinimum(-273.15);
    target->setMaximum(std::numeric_limits<double>::max());
    form->addRow("Target ", target);

    connect(unit, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TemperatureEditor::unitChangedIndex);
}

TemperatureEditor::~TemperatureEditor() = default;

void TemperatureEditor::setTemperatureValues(char u){
    if(u == 'c'){
        min->setValue(min_temp.getCelsius());
        max->setValue(max_temp.getCelsius());
        initial->setValue(initial_temp.getCelsius());
        target->setValue(target_temp.getCelsius());
    }else if(u == 'f'){
        min->setValue(min_temp.getFahrenheit());
        max->setValue(max_temp.getFahrenheit());
        initial->setValue(initial_temp.getFahrenheit());
        target->setValue(target_temp.getFahrenheit());
    }else if(u == 'k'){
        min->setValue(min_temp.getKelvin());
        max->setValue(max_temp.getKelvin());
        initial->setValue(initial_temp.getKelvin());
        target->setValue(target_temp.getKelvin());
    }
}


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
        Sensor::EnviromentalConditions::Temperature(target->value(), unit_char),
        unit_char
    ); 
}

void TemperatureEditor::setValues(const Sensor::TemperatureSensor& temperature_sensor){
    unitChangedChar(temperature_sensor.getSimulationScale());

    min_temp = (temperature_sensor.getTempMin());
    max_temp = (temperature_sensor.getTempMax());
    initial_temp = (temperature_sensor.getTempInitial());
    target_temp = (temperature_sensor.getTempTarget());

    unit_char = temperature_sensor.getSimulationScale();

    setTemperatureValues(unit_char);
}

void TemperatureEditor::unitChangedIndex(int index){
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
        setTemperatureValues(unit_char);

        min->setMinimum(-273.15);
        max->setMinimum(-273.15);
        initial->setMinimum(-273.15);
        stdDeviation->setMinimum(0);
        target->setMinimum(-273.15);

    }else if(index == 1){
        min->setSuffix("°F");
        max->setSuffix("°F");
        initial->setSuffix("°F");
        stdDeviation->setSuffix("°F");
        target->setSuffix("°F");

        unit_char = 'f';
        setTemperatureValues(unit_char);

        min->setMinimum(-459.67);
        max->setMinimum(-459.67);
        initial->setMinimum(-459.67);
        stdDeviation->setMinimum(0);
        target->setMinimum(-459.67);

    }else if(index == 2){
        min->setSuffix("K");
        max->setSuffix("K");
        initial->setSuffix("K");
        stdDeviation->setSuffix("K");
        target->setSuffix("K");

        unit_char = 'k';
        setTemperatureValues(unit_char);

        min->setMinimum(0);
        max->setMinimum(0);
        initial->setMinimum(0);
        stdDeviation->setMinimum(0);
        target->setMinimum(0);
    }
}
    void TemperatureEditor::unitChangedChar(char u){
        // index 0 = Celsius
        // index 1 = Fahrenheit
        // index 2 = Kelvin

        if(u == 'c'){
            min->setSuffix("°C");
            max->setSuffix("°C");
            initial->setSuffix("°C");
            stdDeviation->setSuffix("°C");
            target->setSuffix("°C");

            unit->setCurrentIndex(0);

            min->setMinimum(-273.15);
            max->setMinimum(-273.15);
            initial->setMinimum(-273.15);
            stdDeviation->setMinimum(-273.15);
            target->setMinimum(-273.15);

        }else if(u == 'f'){
            min->setSuffix("°F");
            max->setSuffix("°F");
            initial->setSuffix("°F");
            stdDeviation->setSuffix("°F");
            target->setSuffix("°F");

            unit->setCurrentIndex(1);

            min->setMinimum(-459.67);
            max->setMinimum(-459.67);
            initial->setMinimum(-459.67);
            stdDeviation->setMinimum(-459.67);
            target->setMinimum(-459.67);

        }else if(u == 'k'){
            min->setSuffix("K");
            max->setSuffix("K");
            initial->setSuffix("K");
            stdDeviation->setSuffix("K");
            target->setSuffix("K");

            unit->setCurrentIndex(2);

            min->setMinimum(0);
            max->setMinimum(0);
            initial->setMinimum(0);
            stdDeviation->setMinimum(0);
            target->setMinimum(0);
        }
    }

}
