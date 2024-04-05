#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "SearchWidget.h"
#include "ResultWidget.h"

#include "SensorRenderer/Full.h"

namespace View{

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QAction* create_item;
    QToolBar* toolbar;
    // SearchWidget* search_widget;
    QStackedWidget* stacked_widget;
    // ResultsWidget* results_widget;
    SensorRenderer::Full full_renderer;

    void clearStack();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // aggiungi metodi
    
    void showStatusBar(QString m);

    public slots:
    void createItem();
};

}

#endif // MAINWINDOW_H
