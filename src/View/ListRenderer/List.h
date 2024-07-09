#ifndef VIEW_LIST_RENDERER_LIST_H
#define VIEW_LIST_RENDERER_LIST_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include "SRendererStrategy.h"
#include "ListRenderer.h"
#include "../SensorListWidget.h"
#include "../../Engine/SensorList.h"

namespace View::ListRenderer {
    class List : public SRendererStrategy{

        SensorRenderer::ListRenderer list_sensor;

    public:
        void render(QGridLayout* grid, Engine::SensorList* list ,QVector<WidgetLookup>* lookup) override;
    };

}

#endif //VIEW_LIST_RENDERER_LIST_H
