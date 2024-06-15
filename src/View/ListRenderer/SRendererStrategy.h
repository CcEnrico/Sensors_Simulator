#ifndef VIEW_LIST_RENDERER_SRENDERERSTRATEGY_H
#define VIEW_LIST_RENDERER_SRENDERERSTRATEGY_H

#include <QGridLayout>
#include <QVector>

#include "View/SensorLookup/WidgetLookup.h"
#include "../../Engine/SensorList.h"

namespace View::ListRenderer{

    class SRendererStrategy{

    public:

        virtual ~SRendererStrategy() = default;
        virtual void render(QGridLayout* grid, Engine::SensorList* list, QVector<WidgetLookup>* lookup) = 0;

    };

}

#endif //VIEW_LIST_RENDERER_SRENDERERSTRATEGY_H
