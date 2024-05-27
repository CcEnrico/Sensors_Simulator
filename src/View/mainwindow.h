#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "../Sensor/Repository/JsonRepository.h"
#include "SearchWidget.h"
#include "SensorListWidget.h"
#include "EditWindow.h"

namespace View{

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QAction* create_item;
    QToolBar* toolbar;

    // Concettualmente sensor_list , repository e query condividono la stessa memoria (quando repository(e query) esiste e non nullo)
    // Quindi la loro copia e' shallow
    // Altrimenti dovrei fare una deep copy della memoria di sensor_list e repository
    // Ma non voglio perche andrei a creare degli oggetti AbstractSensor duplicati inutili
    // Quindi nei metodi che manipolano la memoria come quelli di aggiunta, rimozione o caricamento di nuovi dataset
    // devo stare attento ad usare la stessa memoria ad aggiungere le stesse locazioni di memoria nei due contenitori
    Engine::SensorList* sensor_list;
    Sensor::Repository::JsonRepository* repository;
    Engine::SensorList* query;

    SearchWidget* search_widget;
    SensorWidget* sensor_widget;
    EditWindow* edit_window;
    SensorListWidget* sensor_list_widget;
    QWidget* previousCentralWidget;

public:
    explicit MainWindow(Engine::SensorList* mem, QWidget *parent = nullptr);
    ~MainWindow() override;

    SensorListWidget* getSensorListWidget();
    Engine::SensorList* getList() const;
    Sensor::Repository::JsonRepository* getRepository() const;
    QAction* getCreateItem();
    
    void showStatusBar(const QString& m);

    MainWindow& reloadMemory();
    MainWindow& ClearMemory();

    public slots:

    void newDataset();
    void openDataset();
    void saveDataset();
    void saveAsDataset();
    void createItem();
    void editItem(Sensor::AbstractSensor* s);
    void finishEdit();
    void search(const std::string& query_text);
};

}

#endif // MAINWINDOW_H
