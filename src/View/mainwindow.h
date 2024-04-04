#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showStatusBar(QString m);
};
#endif // MAINWINDOW_H

}
