#include"SensorListWidget.h"
#include "ListRenderer/List.h"

#include <QScrollArea>

namespace View{

SensorListWidget::SensorListWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);


    layout = new QGridLayout();
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(layout);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);

    renderer = new ListRenderer::List();

    
    

}

void SensorListWidget::showList(Engine::SensorList* list){

    while(!lookup.isEmpty()){
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }

    renderer->render(layout, list , &lookup);

    for (
        QVector<WidgetLookup>::const_iterator it = lookup.begin();
        it != lookup.end();
        it++
    ) {
        if (it->getViewButton()) {
            // connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showItem, this, it->getItem()));
        }
        if (it->getEditButton()) {
            // connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getItem()));
        }
        if (it->getDeleteButton()) {
            // connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getItem()));
        }
    }

}

}
