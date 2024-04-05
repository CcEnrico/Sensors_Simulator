#include "AbstractSensorEditor.h"

#include <QWidget>

namespace View {
namespace SensorEditor {

AbstractSensorEditor::AbstractSensorEditor(QWidget* parent)
    : QWidget(parent)
{
}

AbstractSensorEditor::~AbstractSensorEditor() {
}

}
}