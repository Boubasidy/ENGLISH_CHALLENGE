#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QFileDialog>
#include <QMessageBox>


#include "quatrowidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void nouvelle_partie();
    void aboutQT();
    void aboutQuarto();
    void Historique();


private:

    void createActions();
    void createMenu();
    void createToolBar();

    QAction *_NouvellePartieAction;
    QAction *_HistoriqueAction;
    QAction *_QuitterAction;

    QAction *_AboutQT;
    QAction *_AboutQuatro;


    QuadrantWidget *_quartowidget;
};

#endif // MAINWINDOW_H
