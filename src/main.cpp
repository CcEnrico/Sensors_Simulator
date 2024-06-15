#include "View/mainwindow.h"
#include "Engine/SensorList.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":Assets/icons/icon.svg"));

    Engine::SensorList* memory = new Engine::SensorList();

    View::MainWindow window(memory);
    window.resize(1024, 576);

    window.show();
    return app.exec();
}
