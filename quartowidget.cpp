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

    QPixmap pix(50, 50);
    pix.fill(Qt::transparent);
    QPainter painter(&pix);
    painter.setPen(QColor(31,31,31));



    QPushButton *CLAIRE_PETIT_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(14, 14, 22, 22);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_PETIT_ROND_TROU->setIcon(QIcon(pix));
    CLAIRE_PETIT_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_ROND_TROU);
    CLAIRE_PETIT_ROND_TROU->setObjectName("CLAIRE-PETIT-ROND-TROU");
    connect(CLAIRE_PETIT_ROND_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    connect(CLAIRE_PETIT_ROND_TROU, &QPushButton::clicked, this, [=]() {
            CLAIRE_PETIT_ROND_TROU->setStyleSheet("background-color: green;");
        });
    CLAIRE_PETIT_ROND_TROU->installEventFilter(this);

    