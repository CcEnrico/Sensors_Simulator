#ifndef VIEW_SENSORLISTWIDGET_H
#define VIEW_SENSORLISTWIDGET_H

#include"WidgetLookup.h"
#include "ListRenderer/SRendererStrategy.h"
#include "SensorWidget.h"

#include <QVector>
#include <QGridLayout>
#include <QWidget>

namespace View{

class SensorListWidget : public QWidget
{
private:
    SensorWidget* sensor_widget;
    QVector<WidgetLookup> lookup;
    QGridLayout* layout;
    ListRenderer::SRendererStrategy* renderer;


public:

    explicit SensorListWidget( SensorWidget* s_w , QWidget* parent = nullptr);

    void showList(Engine::SensorList* list);
    void editSensor(QVector<WidgetLookup>::const_iterator i);
    void deleteSensor(QVector<WidgetLookup>::const_iterator it, Engine::SensorList* list);
    void clean();

};


}


#endif // SENSORLISTWIDGET_H