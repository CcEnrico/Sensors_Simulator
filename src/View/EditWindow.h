#ifndef VIEW_EDIT_WINDOW_H
#define VIEW_EDIT_WINDOW_H

#include <QMainWindow>

namespace View{
    class EditWindow : public QMainWindow {
        Q_OBJECT
    signals:
        void windowClosed();
    protected:
        void closeEvent(QCloseEvent *event) override;

    };
}




#endif //VIEW_EDIT_WINDOW_H
