#include"SearchWidget.h"

#include <QHBoxLayout>
#include <QPushButton>



namespace View{

    SearchWidget::SearchWidget(QWidget* parent)
    : QWidget(parent)
    {
//        creazione widget ricerca

        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        query = new QLineEdit();
        query->setPlaceholderText("Sensor");
        query->setFixedWidth(400);
        layout->addWidget(query);

        QPushButton* search_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/search.svg")), "Search" );
        search_button->setFixedWidth(100);
        layout->addWidget(search_button);

//        connetti segnali per effetuare la ricerca


    }

}