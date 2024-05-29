#include"EditWidget.h"
#include"TypeSelector.h"
#include"SensorEditor/AirQualityEditor.h"
#include"SensorEditor/HumidityEditor.h"
#include"SensorEditor/TemperatureEditor.h"
#include"SensorEditor/SensorInjector.h"

#include <iostream>

#include <typeinfo>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <QMessageBox>

namespace View {

EditWidget::EditWidget(
    Sensor::AbstractSensor* s,
    MainWindow* m,
    Sensor::Repository::JsonRepository* repo
    ): sensor(s), main_window(m), repository(repo)
{

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setObjectName("Edit Widget");

    QLabel* title = new QLabel("Edit Sensor");
    title->setObjectName("title");
    layout->addWidget(title);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("Properties Form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    layout->addLayout(form);

    id_input = new QSpinBox();
    id_input->setObjectName("Identifier Input");
    id_input->setRange(0, 9999);

    if(sensor != nullptr){
        id_input->setValue(sensor->getIdentifier());
    }
    form->addRow("Identifier", id_input);

    name_input = new QLineEdit();
    name_input->setObjectName("Name Input");
    name_input->setPlaceholderText("Sensor Name");
    name_input->setMaxLength(20);

    if (sensor != nullptr){
        name_input->setText(QString::fromStdString(sensor->getName()));
    }   
    form->addRow("Name", name_input);

    dataNum_input = new QSpinBox();
    dataNum_input->setObjectName("Data Number Input");
    dataNum_input->setRange(1, 10000);
    dataNum_input->setValue(100);

    if(sensor != nullptr){
        dataNum_input->setValue(sensor->getDataNum());
    }
    form->addRow("Data Number", dataNum_input);

    variance_input = new QDoubleSpinBox();
    variance_input->setObjectName("Variance Input");
    variance_input->setRange(0.0, 1000.0);
    variance_input->setDecimals(2);
    if(sensor != nullptr){
        variance_input->setValue(sensor->getVariance());
    }
    form->addRow("Variance", variance_input);


    QComboBox* type_input = new QComboBox();
    type_input->setObjectName("Type Input");
    type_input->addItem("AirqualitySensor");    // indice 0
    type_input->addItem("HumiditySensor");  // indice 1
    type_input->addItem("TemperatureSensor"); // indice 2
    
    if (sensor != nullptr) {
        TypeSelector type_selector(type_input);
        sensor->accept(type_selector);
    }

    form->addRow("type", type_input);

    stacked_editor = new QStackedLayout();
    layout->addLayout(stacked_editor);

    

    SensorEditor::AirQualityEditor* air_quality_editor = new SensorEditor::AirQualityEditor();
    stacked_editor->addWidget(air_quality_editor);
    editors.push_back(air_quality_editor);

    SensorEditor::HumidityEditor* humidity_editor = new SensorEditor::HumidityEditor();
    stacked_editor->addWidget(humidity_editor);
    editors.push_back(humidity_editor);

    SensorEditor::TemperatureEditor* temperature_editor = new SensorEditor::TemperatureEditor();
    stacked_editor->addWidget(temperature_editor);
    editors.push_back(temperature_editor);
    connect(this, &EditWidget::set_unit_event, temperature_editor, &SensorEditor::TemperatureEditor::unitChangedChar);

    if (sensor != nullptr) {
        SensorEditor::SensorInjector sensor_injector(
            *air_quality_editor,
            *humidity_editor,
            *temperature_editor
        );
        sensor->accept(sensor_injector);

        Sensor::TemperatureSensor* unit_setter = dynamic_cast<Sensor::TemperatureSensor*>(sensor);
        if (unit_setter != nullptr){
            emit set_unit_event(unit_setter->getSimulationScale());
        }
    }
    showType(type_input->currentIndex());


    layout->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setObjectName("actions");
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addLayout(actions);

    actions->addStretch();

    QPushButton* apply_button = new QPushButton("Apply");
    apply_button->setObjectName("apply");
    actions->addWidget(apply_button);

    QPushButton* cancel_button = new QPushButton("Cancel");
    cancel_button->setObjectName("cancel");
    actions->addWidget(cancel_button);



    // Connects signals
    connect(type_input, qOverload<int>(&QComboBox::currentIndexChanged), this, &EditWidget::showType);
    connect(apply_button, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancel_button, &QPushButton::clicked, this, &EditWidget::closeWindow);

}

void EditWidget::selectImage(){}

void EditWidget::showType(int index){
    stacked_editor->setCurrentIndex(index);
}

void EditWidget::apply(){

    int id = id_input->value();
    QString name = name_input->text();
    int dn = dataNum_input->value();
    double v = variance_input->value();
    SensorEditor::AbstractSensorEditor* editor = editors[stacked_editor->currentIndex()];

    Engine::SensorList* list = main_window->getList();

    // in caso io stia solo modificando un sensore preesistente, lo tolgo dalla  memoria della repo, e da quella della mem e dealloco
    if (sensor != nullptr) {
        if (repository != nullptr) repository->erase(sensor->getIdentifier());
        list->remove(sensor);
    }
    sensor = editor->create(id, name, dn, v);


    // se il sensore esiste già
    if (list->find(sensor)){
        QMessageBox::critical(this, "Error", "ID taken");
    }else{
        list->add(sensor);

        // json aggiornamento
        if(repository != nullptr) {
            repository->update(sensor);
        }

        main_window->finishEdit();
    }
}


void EditWidget::closeWindow(){
    main_window->closeEdit();
}

}
