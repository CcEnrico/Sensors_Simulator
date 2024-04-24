#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>


#include "SearchWidget.h"
#include "SensorListWidget.h"
#include "SensorWidget.h"



namespace View{

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QAction* create_item;
    QToolBar* toolbar;
    Engine::SensorList* sensor_list;
    SensorWidget* sensor_widget;
    QMainWindow* edit_window;
    SensorListWidget* sensor_list_widget;


public:
    explicit MainWindow(Engine::SensorList* mem, QWidget *parent = nullptr);
    ~MainWindow() override;

    SensorListWidget* getSensorListWidget();
    Engine::SensorList* getList() const;
    QAction* getCreateItem();


    // aggiungi metodi
    
    void showStatusBar(const QString& m);
    void finishEdit();
    

    public slots:
    void createItem();
};

}

#endif // MAINWINDOW_H
