#ifndef VIEW_MAINWINDOW_H
#define VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>


#include "SearchWidget.h"
#include "SensorListWidget.h"

#include "SensorRenderer/Full.h"
#include "../Engine/SensorList.h"



namespace View{

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QAction* create_item;
    QToolBar* toolbar;
    Engine::SensorList* sensor_list;
    // SearchWidget* search_widget;
    QStackedWidget* stacked_widget;
    SensorListWidget* sensor_list_widget;
    SensorRenderer::Full full_renderer;

    void clearStack();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    SensorListWidget* getSensorListWidget();
    Engine::SensorList* getList() const;


    // aggiungi metodi
    
    void showStatusBar(const QString& m);
    void finishEdit();
    

    public slots:
    void createItem();
};

}

#endif // MAINWINDOW_H
