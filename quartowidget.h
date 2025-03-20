#ifndef QUADRANTWIDGET_H
#define QUADRANTWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QDialog>
#include <string>
#include <iostream>

class QuadrantWidget : public QWidget
{
    Q_OBJECT

public:
    QuadrantWidget(QWidget *parent = nullptr);
    ~QuadrantWidget();
    std::vector<QLabel*> & getHistoricalLabels(){
        return _Historical_Labels;
    }
    void writeLabelsToFile(const QString& filename, const std::vector<QLabel*>& labels);

public slots:
    void Choose_Piece();
    void Place_Piece(int row,int col);
    void Changement_joueur();
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QIcon Iconselected;
    QHBoxLayout *piecesLayout;
    int PlayerNumber=1;
    std::string _status = "Active Player: " + std::to_string(PlayerNumber) + "\nPlayer " + std::to_string((PlayerNumber==1)?2:1) + " must pick a piece for Player " + std::to_string(PlayerNumber) + " to play.";
    std::string _footer="";
    QLabel *statusLabel;
    QLabel *footerLabel;
    std::vector<QLabel*> _Historical_Labels;
    int _column;
    int _row;
    int _index;

};

#endif // QUADRANTWIDGET_H