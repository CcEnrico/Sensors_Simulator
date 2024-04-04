#include "mainwindow.h"

#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QSplitter>

namespace View{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Action

    QAction* create = new QAction(
        QIcon(QPixmap((":/Assets/icons/new.svg"))),
        "New"
    );
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
    create_item->setEnabled(false);

    // Menu
    QMenu* menu_bar = menuBar()->addMenu("&File");
    menu_bar->addAction(create);
    menu_bar->addAction(open);
    menu_bar->addAction(save);
    menu_bar->addAction(save_as);
    menu_bar->addSeparator();
    menu_bar->addAction(close);
    QMenu* view_menu = menuBar()->addMenu("&View");
    view_menu->addAction(togge_toolbar);
    QMenu* item_menu = menuBar()->addMenu("&Item");
    item_menu->addAction(create_item);

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

    stacked_widget = new QStackedWidget(this);
    splitter->addWidget(stacked_widget);

    // item_widget = new ItemWidget();
    

    splitter->setSizes(QList<int>() << 1000 << 3000);

    showStatusBar("Ready.");
}

MainWindow::~MainWindow()
{
}

void MainWindow::showStatusBar(QString message)
{
    statusBar()->showMessage(message);
}


} 

