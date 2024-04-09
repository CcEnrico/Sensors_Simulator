#ifndef PAO_SENSORI_ECC_LIST_H
#define PAO_SENSORI_ECC_LIST_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include "SRendererStrategy.h"
#include "../SensorRenderer/ListSensor.h"
#include "../SensorListWidget.h"
#include "../../Engine/SensorList.h"

namespace View::ListRenderer {
    class List : public SRendererStrategy{
        SensorRenderer::ListSensor list_sensor;

    public:
        void render(QGridLayout* grid, Engine::SensorList* list ,QVector<WidgetLookup>* lookup) override;
    };

}

#endif //PAO_SENSORI_ECC_LIST_H
