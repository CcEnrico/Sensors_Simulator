#ifndef VIEW_SENSORLISTWIDGET_H
#define VIEW_SENSORLISTWIDGET_H

#include"WidgetLookup.h"

#include <QVector>
#include <QGridLayout>
#include <QWidget>

namespace View{

class SensorListWidget : public QWidget
{
private:
    
    QVector<WidgetLookup> lookup;
    QGridLayout* layout;


public:

    explicit SensorListWidget(QWidget* parent = 0);

    void show();

};


}


#endif // SENSORLISTWIDGET_H