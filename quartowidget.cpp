#include<math.h>
#include <sstream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QDebug>
#include <fstream>

std::vector<std::string> split(const std::string& charac, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream charss(charac);
    std::string token;
    while (std::getline(charss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

QuadrantWidget::QuadrantWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    piecesLayout = new QHBoxLayout;
    QGridLayout *boardLayout = new QGridLayout;
    statusLabel = new QLabel(QString::fromStdString(_status));

    for (int i = 0; i < 16; ++i) {
        QPushButton *pieceButton = new QPushButton;
        pieceButton->setFixedSize(60,60);
        //pieceButton->setIcon(QIcon(pix));
        pieceButton->setIconSize(pix.size());

        int row = floor(i / 4);
        int col = i % 4;
        boardLayout->addWidget(pieceButton, row, col);
        //connect(pieceButton, &QPushButton::clicked, this, &quatrowidget::Put_Piece);
        connect(pieceButton, &QPushButton::clicked, this, [this, row, col]() {Place_Piece(row, col);});
    }