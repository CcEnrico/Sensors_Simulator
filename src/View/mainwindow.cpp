#include "mainwindow.h"
#include "EditWidget.h"

#include "../Sensor/DataMapper/JsonFile.h"
#include "../Sensor/Converter/Json/Reader.h"
#include "../Sensor/Converter/Json/Json.h"

#include <QWidget>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QSplitter>
#include <QScrollArea>
#include <QLabel>
#include <QWindow>
#include <QFileDialog>
#include <QMessageBox>


namespace View{

MainWindow::MainWindow( Engine::SensorList* mem, QWidget *parent )
    :   QMainWindow(parent),
    sensor_list(mem),
    repository(nullptr)
{

    // Action

    QAction* create = new QAction(
        QIcon(QPixmap((":/Assets/icons/new.svg"))),
        "New"
    );
    create->setEnabled(true);
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    QAction* open = new QAction(
        QIcon(QPixmap((":/Assets/icons/open.svg"))),
        "Open"
    );
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* save = new QAction(
        QIcon(QPixmap((":/Assets/icons/save.svg"))),
        "Save"
    );
    save->setEnabled(true);
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* save_as = new QAction(
        QIcon(QPixmap((":/Assets/icons/save_as.svg"))),
        "Save As"
    );
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    QAction* close = new QAction(
        QIcon(QPixmap((":/Assets/icons/close.svg"))),
        "Close"
    );
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    QAction* togge_toolbar = new QAction(
        "Toolbar"
    );
    create_item = new QAction(
        QIcon(QPixmap((":/Assets/icons/new_item.svg"))),
        "New Item"
    );
    create_item->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_item->setEnabled(true);

    // Menu
//    QMenu* menu_bar = menuBar()->addMenu("&File");
//    menu_bar->addAction(create);
//    menu_bar->addAction(open);
//    menu_bar->addAction(save);
//    menu_bar->addAction(save_as);
//    menu_bar->addSeparator();
//    menu_bar->addAction(close);
//    QMenu* view_menu = menuBar()->addMenu("&View");
//    view_menu->addAction(togge_toolbar);
//    QMenu* item_menu = menuBar()->addMenu("&Item");
//    item_menu->addAction(create_item);

    // toolbar
    toolbar = addToolBar("Toolbar");
    toolbar->setOrientation(Qt::Vertical);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(save_as);
    toolbar->addAction(close);
    toolbar->addAction(create_item);

    // panel
    QSplitter* splitter = new QSplitter(this);
    setCentralWidget(splitter);

    // search_widget = new SearchWidget();

    sensor_widget = new SensorWidget(this); 
    sensor_list_widget = new SensorListWidget(sensor_widget ,this);

    splitter->addWidget(sensor_list_widget);   
    splitter->addWidget(sensor_widget);

    // item_widget = new ItemWidget();


    splitter->setSizes(QList<int>() << 1000 << 3000);

    edit_window = new EditWindow();

    // connect
    connect(create, &QAction::triggered, this, &MainWindow::newDataset);
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsDataset);
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);
    connect(create_item, &QAction::triggered, this, &MainWindow::createItem);
    connect(edit_window, &EditWindow::windowClosed, this, &MainWindow::finishEdit);

    showStatusBar("Ready.");
}

MainWindow::~MainWindow()
{
    delete sensor_list;
}

MainWindow& MainWindow::ClearMemory(){

    if (repository != nullptr) {

        delete repository;  // dealloca gli oggetti contenuti nella map (distruttore ridefinito)
        repository = nullptr;

        sensor_list->clean();   // svuota lista

    }else if( repository == nullptr && !(sensor_list->isEmpty())){
        sensor_list->clear();   // dealloca e svuota lista
    }
    return *this;
}

MainWindow& MainWindow::reloadMemory() {

    std::vector<Sensor::AbstractSensor*> sensors(repository->readAll());
    for (auto it = sensors.begin(); it != sensors.end(); ++it ) {
        sensor_list->add(*it);
    }

    return *this;
}

void MainWindow::newDataset(){

    QString path = QFileDialog::getSaveFileName(
            this,
            "Creates new Dataset",
            "./Assets/DataJson/",
            "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }

    try{

//        Sensor::Converter::Json::Reader reader;
//        Sensor::Converter::Json::Json converter(reader);
//        Sensor::DataMapper::JsonFile data_mapper(path.toStdString(), converter);
//        Sensor::Repository::JsonRepository* r = new Sensor::Repository::JsonRepository(data_mapper);
        // membro statico fa esattamente quello che fanno le righe commentate sopra, attenzione alloca memoria
        Sensor::Repository::JsonRepository* r = Sensor::Repository::JsonRepository::fromPath(path.toStdString());
        if (!r->empty()) {
            throw std::runtime_error("Repository is not empty as expected");
        }
        ClearMemory();

        repository = r;

        sensor_widget->clean();
        sensor_list_widget->clean();

        sensor_list_widget->showList(sensor_list, repository);

        showStatusBar("New dataset created.");

    }catch (const std::exception& e) {
        qDebug() << "Error creating new dataset: " << e.what();
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::saveDataset() {

    if (repository == nullptr) {
        return;
    }
    repository->store();
    showStatusBar("Dataset saved.");
}

void MainWindow::openDataset(){

    QString path = QFileDialog::getOpenFileName(
            this,
            "Open Dataset",
            "./Assets/DataJson/",
            "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }

    ClearMemory();

    repository = Sensor::Repository::JsonRepository::fromPath(path.toStdString());
    sensor_widget->clean();
    sensor_list_widget->clean();

    reloadMemory();

    sensor_list_widget->showList(sensor_list, repository);


    showStatusBar("Data successfully loaded from " + path + ".");
}


void MainWindow::saveAsDataset(){
    QString path = QFileDialog::getSaveFileName(
            this,
            "Creates new Dataset",
            "./Assets/DataJson/",
            "JSON files *.json"
    );
    if (path.isEmpty() || repository == nullptr) {
        return;
    }
    repository->setPath(path.toStdString()).store();
    showStatusBar("Dataset saved as \"" + path + "\".");
}


void MainWindow::createItem()
{
    create_item->setEnabled(false);

    EditWidget* edit = new EditWidget(nullptr, this, repository);

    edit_window->setCentralWidget(edit);
    edit_window->show();

    showStatusBar("Creating a new item.");
}

void MainWindow::editItem(Sensor::AbstractSensor* s)
{
    create_item->setEnabled(false);
    EditWidget* edit = new EditWidget(s, this, repository);
    edit_window->setCentralWidget(edit);
    edit_window->show();
    showStatusBar("Editing a Sensor.");
}

void MainWindow::finishEdit()
{
    edit_window->close();
    delete edit_window->centralWidget();

    create_item->setEnabled(true);

    sensor_list_widget->showList(sensor_list);
    if (!sensor_widget->isEmpty()) sensor_widget->hideSensorWidget();
    showStatusBar("Ready.");
}

SensorListWidget* MainWindow::getSensorListWidget(){
    return sensor_list_widget;

}

Engine::SensorList* MainWindow::getList() const {
    return sensor_list;
}

Sensor::Repository::JsonRepository* MainWindow::getRepository() const{
    return repository;
}

QAction* MainWindow::getCreateItem(){
    return create_item;
}

void MainWindow::showStatusBar(const QString& message)
{
    statusBar()->showMessage(message);
}


} 

