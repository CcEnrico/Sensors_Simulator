#include "AbstractSensorEditor.h"

#include <QWidget>


namespace View::SensorEditor {

AbstractSensorEditor::AbstractSensorEditor(QWidget* parent)
    : QWidget(parent)
{
}

AbstractSensorEditor::~AbstractSensorEditor() = default;

}
