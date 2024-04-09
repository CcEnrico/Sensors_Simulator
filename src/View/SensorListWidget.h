#ifndef VIEW_SENSORLISTWIDGET_H
#define VIEW_SENSORLISTWIDGET_H

#include"WidgetLookup.h"
#include "ListRenderer/SRendererStrategy.h"

#include <QVector>
#include <QGridLayout>
#include <QWidget>

namespace View{

class SensorListWidget : public QWidget
{
private:
    
    QVector<WidgetLookup> lookup;
    QGridLayout* layout;
    ListRenderer::SRendererStrategy* renderer;


public:

    explicit SensorListWidget(QWidget* parent = 0);

    void showList(Engine::SensorList* list);

};


}


#endif // SENSORLISTWIDGET_H