#include "View/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":Assets/icon.svg"));

    View::MainWindow window;
    window.resize(1024, 576);

    window.show();
    return app.exec();
}
