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
#include "../Sensor/Repository/JsonRepository.h"

namespace View {

class EditWidget : public QWidget{
    Q_OBJECT
  private:
    Sensor::AbstractSensor* sensor;
    MainWindow* main_window;
    QSpinBox* id_input;
    QLineEdit* name_input;
    QSpinBox* dataNum_input;
    QDoubleSpinBox* variance_input;
    QStackedLayout* stacked_editor;
    QVector<SensorEditor::AbstractSensorEditor*> editors;
    Sensor::Repository::JsonRepository* repository;


  public:
    EditWidget(
      Sensor::AbstractSensor* s,
      MainWindow* m,
      Sensor::Repository::JsonRepository* repo = nullptr
    );

signals:
    void widgetClosed();

    void set_unit_event(int index);

    
  public slots:
    void selectImage();
    void showType(int index);
    void apply();
    void closeWindow();

};

}

#endif // EDIT_WIDGET_H