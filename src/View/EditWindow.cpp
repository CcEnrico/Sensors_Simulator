#include "EditWindow.h"


namespace View{
    void EditWindow::closeEvent(QCloseEvent *event) {
        emit windowClosed();
        QMainWindow::closeEvent(event);
    }
}