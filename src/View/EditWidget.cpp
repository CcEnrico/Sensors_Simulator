#include"EditWidget.h"

#include <iostream>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>


namespace View {

EditWidget::EditWidget(
    MainWindow* mainWindow, 
    const Sensor::AbstractSensor* sensor
    )
    : main_window(main_window), subject()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setObjectName("widget-edit");
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* title = new QLabel("Item properties");
    title->setObjectName("title");
    vbox->addWidget(title);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("properties-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    vbox->addLayout(form);

    identifier_input = new QSpinBox();
    identifier_input->setObjectName("identifier-input");
    identifier_input->setMinimum(1);
    identifier_input->setMaximum(INT_MAX);

    if (subject != nullptr) {
        identifier_input->setValue(subject->getIdentifier());
    }
    form->addRow("identifier", identifier_input);

    name_input = new QLineEdit();
    name_input->setObjectName("name-input");
    if (subject != nullptr) {
        name_input->setText(QString::fromStdString(subject->getName()));
    }
    form->addRow("name", name_input);
    

    stacked_editor = new QStackedLayout();
    vbox->addLayout(stacked_editor);

    // modifica editors
    // ItemEditor::WebPageEditor* web_page_editor = new ItemEditor::WebPageEditor();
    // stacked_editor->addWidget(web_page_editor);
    // editors.push_back(web_page_editor);

    // ItemEditor::SimpleEditor* simple_editor = new ItemEditor::SimpleEditor();
    // stacked_editor->addWidget(simple_editor);
    // editors.push_back(simple_editor);

    // ItemEditor::VirtualEditor* virtual_editor = new ItemEditor::VirtualEditor();
    // stacked_editor->addWidget(virtual_editor);
    // editors.push_back(virtual_editor);


    vbox->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setObjectName("actions");
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(actions);

    actions->addStretch();

    QPushButton* apply_button = new QPushButton("Apply");
    apply_button->setObjectName("apply");
    actions->addWidget(apply_button);

    QPushButton* cancel_button = new QPushButton("Cancel");
    cancel_button->setObjectName("cancel");
    actions->addWidget(cancel_button);

    // Connects signals

}

void EditWidget::selectImage(){}
void EditWidget::showType(int index){}
void EditWidget::apply(){}

}