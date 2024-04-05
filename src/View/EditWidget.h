#ifndef VIEW_EDIT_WIDGET_H
#define VIEW_EDIT_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QStackedLayout>

#include "mainwindow.h"
#include "../Sensor/AbstractSensor.h"
#include "SensorEditor/AbstractSensorEditor.h"

namespace View {

class EditWidget : public QWidget{
    Q_OBJECT
  private:
    MainWindow* main_window;
    const Sensor::AbstractSensor* subject;
    QSpinBox* identifier_input;
    QLineEdit* name_input;
    QTextEdit* description_input;
    QLineEdit* image_input;
    QStackedLayout* stacked_editor;
    QVector<SensorEditor::AbstractSensorEditor*> editors;

  public:
    EditWidget(
      MainWindow* main_window,
      const Sensor::AbstractSensor* subject
    );
    
  public slots:
    void selectImage();
    void showType(int index);
    void apply();
};

}

#endif // EDIT_WIDGET_H