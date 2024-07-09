#include "mainwindow.h"
#include "EditWidget.h"

#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QSplitter>
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
    // alloca la memoria della query
    query = new Engine::SensorList();

    // azioni

    create = new QAction(
        QIcon(QPixmap((":/Assets/icons/new.svg"))),
        "New"
    );
    create->setEnabled(true);

    open = new QAction(
        QIcon(QPixmap((":/Assets/icons/open.svg"))),
        "Open"
    );

    save = new QAction(
        QIcon(QPixmap((":/Assets/icons/save.svg"))),
        "Save"
    );
    save->setEnabled(true);
    
    save_as = new QAction(
        QIcon(QPixmap((":/Assets/icons/save_as.svg"))),
        "Save As"
    );
    
    create_sensor = new QAction(
        QIcon(QPixmap((":/Assets/icons/new_item.svg"))),
        "New Item"
    );
    create_sensor->setEnabled(true);
    help = new QAction(
            QIcon(QPixmap((":/Assets/icons/help.svg"))),
            "Help"
    );
    help->setEnabled(true);

    create->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_C));
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    create_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    help->setShortcut(QKeySequence(Qt::Key_F1));

    // toolbar
    toolbar = addToolBar("Toolbar");
    toolbar->setOrientation(Qt::Vertical);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(save_as);
    toolbar->addAction(create_sensor);
    toolbar->addAction(help);

    // panel

    QSplitter* vertical_splitter = new QSplitter(Qt::Vertical,this);
    setCentralWidget(vertical_splitter);

    search_widget = new SearchWidget(this);
    vertical_splitter->addWidget(search_widget);

    QSplitter* splitter = new QSplitter(this);
    vertical_splitter->addWidget(splitter);

    sensor_widget = new SensorWidget(this);
    sensor_list_widget = new SensorListWidget(sensor_widget ,this);

    splitter->addWidget(sensor_list_widget);
    splitter->addWidget(sensor_widget);

    vertical_splitter->setHandleWidth(0);
    vertical_splitter->setSizes(QList<int>() << 100 << 3000);
    splitter->setSizes(QList<int>() << 1000 << 3000);

    edit_window = new EditWindow();

    // connect
    connect(create, &QAction::triggered, this, &MainWindow::newDataset);
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsDataset);
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);
    connect(create_sensor, &QAction::triggered, this, &MainWindow::createItem);
    connect(help, &QAction::triggered, this, &MainWindow::showHelpDialog);
    connect(edit_window, &EditWindow::windowClosed, this, &MainWindow::closeEdit);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(sensor_list_widget, &SensorListWidget::sortId_event, this, &MainWindow::sortSensorsId);
    connect(sensor_list_widget, &SensorListWidget::sortName_event, this, &MainWindow::sortSensorsName);
    connect(sensor_list_widget, &SensorListWidget::edit_event, this, &MainWindow::editItem);
    connect(sensor_widget, &SensorWidget::edit_event, this, &MainWindow::editItem);

    showStatusBar("Ready.");
}

MainWindow::~MainWindow()
{
    query->clean();
    delete query;
    delete sensor_list;
    delete edit_window;

    // cancella azioni
    delete create;
    delete open;
    delete save;
    delete save_as;
    delete create_sensor;
}

MainWindow& MainWindow::ClearMemory(){

    repository = nullptr;
    sensor_list->clear();   // dealloca e svuota lista

    return *this;
}

MainWindow& MainWindow::reloadMemory() {

    std::vector<Sensor::AbstractSensor*> sensors(repository->readAll());
    for (auto it = sensors.begin(); it != sensors.end(); ++it ) {
        sensor_list->add(*it);
    }

    return *this;
}

MainWindow& MainWindow::ClearQuery() {
    query->clean();
    return *this;
}

void MainWindow::newDataset(){

    ClearQuery();

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

        sensor_list_widget->showList(sensor_list, repository, query);

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

    ClearQuery();

    QString path = QFileDialog::getOpenFileName(
            this,
            "Open Dataset",
            "./Assets/DataJson/",
            "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }

    try{
        ClearMemory();
        repository = Sensor::Repository::JsonRepository::fromPath(path.toStdString());
        sensor_widget->clean();
        sensor_list_widget->clean();

        reloadMemory();

        sensor_list_widget->showList(sensor_list, repository, query);


        showStatusBar("Data successfully loaded from " + path + ".");
    }catch(const std::exception& e){
        qDebug() << "Error Opening File: " << e.what();
        QMessageBox::critical(this, "Error", e.what());
    }

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
    // svuota query
    ClearQuery();
    create_sensor->setEnabled(false);
    EditWidget* edit = new EditWidget(nullptr, this, repository);
    edit_window->setCentralWidget(edit);
    edit_window->show();

    showStatusBar("Creating a new item.");
}

void MainWindow::showHelpDialog(){
    QMessageBox::information(this, "Shortcut Information",
                             "Keyboard Shortcuts:\n"
                             "Create: Ctrl + Shift + C\n"
                             "Open: Ctrl + O\n"
                             "Save: Ctrl + S\n"
                             "Save As: Ctrl + Shift + S\n"
                             "Create Sensor: Ctrl + N\n"
                             "Help: F1");
}

void MainWindow::editItem(Sensor::AbstractSensor* s)
{
    create_sensor->setEnabled(false);
    EditWidget* edit = new EditWidget(s, this, repository);
    edit_window->setCentralWidget(edit);
    edit_window->show();
    showStatusBar("Editing a Sensor.");
}

void MainWindow::finishEdit()
{
    edit_window->close();
    delete edit_window->centralWidget();
    create_sensor->setEnabled(true);

    // svuota query
    ClearQuery();
    // query qua sara' sempre vuota conviene non passarla
    sensor_list_widget->showList(sensor_list, repository);
    if (!sensor_widget->isEmpty()) sensor_widget->hideSensorWidget();
    showStatusBar("Ready.");
}

void MainWindow::closeEdit(){
    edit_window->close();
    delete edit_window->centralWidget();
    create_sensor->setEnabled(true);
    showStatusBar("Ready.");
}

void MainWindow::search(const std::string& query_text) {
    // svuota la query
    ClearQuery();
    sensor_list->search(query, query_text);
    if (query->isEmpty()){
        showStatusBar("No Match for Query \"" + QString::fromStdString(query_text) + "\"," );
    }else{
        sensor_list_widget->showList( sensor_list, repository, query );
        showStatusBar("Found " + QString::fromStdString(std::to_string(query->size())) + " Match For Query: \"" + QString::fromStdString(query_text) + "\"," );
    }
}

void MainWindow::sortSensorsId() {
    if (!query->isEmpty()) {
        query->sortId();
        sensor_list_widget->showList(sensor_list, repository, query);
    }
    else{
        sensor_list->sortId();
        sensor_list_widget->showList(sensor_list, repository);
    }
}

void MainWindow::sortSensorsName() {
    if (!query->isEmpty()) {
        query->sortName();
        sensor_list_widget->showList(sensor_list, repository, query);
    }
    else{
        sensor_list->sortName();
        sensor_list_widget->showList(sensor_list, repository);
    }
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
    return create_sensor;
}

void MainWindow::showStatusBar(const QString& message)
{
    statusBar()->showMessage(message);
}


} 

