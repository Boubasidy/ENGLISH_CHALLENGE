#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   this->setWindowIcon(QIcon("Bureau/projet/images/Quarto.jpg"));
    _quartowidget = new QuadrantWidget(this);
    setCentralWidget(_quartowidget);

    createActions();
    createMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions() {
    _NouvellePartieAction = new QAction(tr("Nouvelle partie"), this);
    _NouvellePartieAction->setShortcut(tr("CTRL+N"));
    connect(_NouvellePartieAction, &QAction::triggered, this, &MainWindow::nouvelle_partie);

    _HistoriqueAction = new QAction(tr("Voir l'historique"), this);
    _HistoriqueAction->setShortcut(tr("CTRL+H"));
    connect(_HistoriqueAction, &QAction::triggered, this, &MainWindow::Historique);

    _QuitterAction = new QAction(tr("Quitter"), this);
    _QuitterAction->setShortcut(QKeySequence::Quit);
    connect(_QuitterAction, &QAction::triggered, this, &QApplication::quit);

    _AboutQT = new QAction(tr("À propos de QT"), this);
    connect(_AboutQT, &QAction::triggered, this, &MainWindow::aboutQT);


    _AboutQuatro = new QAction(tr("À propos de Quatro"), this);
    connect(_AboutQuatro, &QAction::triggered, this, &MainWindow::aboutQuarto);


}

void MainWindow::createMenu() {
    QMenu *fileMenu = menuBar()->addMenu(tr("Fichier"));
    fileMenu->addAction(_NouvellePartieAction);
    fileMenu->addAction(_HistoriqueAction);
    fileMenu->addSeparator();
    fileMenu->addAction(_QuitterAction);


    QMenu *editMenu = menuBar()->addMenu(tr("À propos"));
    editMenu->addAction(_AboutQT);
    editMenu->addAction(_AboutQuatro);
}

void MainWindow::nouvelle_partie() {
    delete _quartowidget;
    _quartowidget = new QuadrantWidget(this);
    setCentralWidget(_quartowidget);
}
