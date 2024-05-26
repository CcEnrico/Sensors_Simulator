#ifndef VIEW_SEARCHWIDGET_H
#define VIEW_SEARCHWIDGET_H

#include <QWidget>
#include <QLineEdit>

namespace View {
    class SearchWidget: public QWidget{
        Q_OBJECT
    private:

        QLineEdit* query;

    public:

        explicit SearchWidget(QWidget* parent = nullptr);


    };
}

#endif // SEARCHWIDGET_H