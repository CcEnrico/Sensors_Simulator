#ifndef VIEW_SENSORLISTWIDGET_H
#define VIEW_SENSORLISTWIDGET_H

#include "View/SensorLookup/WidgetLookup.h"
#include "ListRenderer/SRendererStrategy.h"
#include "SensorWidget.h"
#include "../Sensor/Repository/JsonRepository.h"

#include <QVector>
#include <QGridLayout>
#include <QWidget>

namespace View{

class SensorListWidget : public QWidget
{
Q_OBJECT
private:
    SensorWidget* sensor_widget;
    QVector<WidgetLookup> lookup;
    QGridLayout* layout;
    ListRenderer::SRendererStrategy* renderer;

public:

    explicit SensorListWidget( SensorWidget* s_w , QWidget* parent = nullptr);
    ~SensorListWidget() override;

    void showList(Engine::SensorList* list, Sensor::Repository::JsonRepository* repository = nullptr, Engine::SensorList* query = nullptr);
    void editSensor(QVector<WidgetLookup>::const_iterator i);
    void deleteSensor(QVector<WidgetLookup>::const_iterator it, Engine::SensorList* list, Sensor::Repository::JsonRepository* repository, Engine::SensorList* query);
    void clean();

public slots:

    void sortId();
    void sortName();

signals:
    void sortId_event();
    void sortName_event();

};

}


#endif // VIEW_SENSORLISTWIDGET_H