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

    QPushButton *CLAIRE_PETIT_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(14, 14, 22, 22);
    CLAIRE_PETIT_ROND_PLEIN->setIcon(QIcon(pix));
    CLAIRE_PETIT_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_ROND_PLEIN);
    connect(CLAIRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    CLAIRE_PETIT_ROND_PLEIN->setObjectName("CLAIRE-PETIT-ROND-PLEIN");
    connect(CLAIRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, [=]() {
            CLAIRE_PETIT_ROND_PLEIN->setStyleSheet("background-color: green;");
        });
    CLAIRE_PETIT_ROND_PLEIN->installEventFilter(this);

    QPushButton *CLAIRE_GRAND_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(1, 1, 48, 48);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_GRAND_ROND_TROU->setIcon(QIcon(pix));
    CLAIRE_GRAND_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_ROND_TROU);
    connect(CLAIRE_GRAND_ROND_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    CLAIRE_GRAND_ROND_TROU->setObjectName("CLAIRE-GRAND-ROND-TROU");
    connect(CLAIRE_GRAND_ROND_TROU, &QPushButton::clicked, this, [=]() {
            CLAIRE_GRAND_ROND_TROU->setStyleSheet("background-color: green;");
        });
    CLAIRE_GRAND_ROND_TROU->installEventFilter(this);

    QPushButton *CLAIRE_GRAND_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(1, 1, 48, 48);
    CLAIRE_GRAND_ROND_PLEIN->setIcon(QIcon(pix));
    CLAIRE_GRAND_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_ROND_PLEIN);
    connect(CLAIRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    CLAIRE_GRAND_ROND_PLEIN->setObjectName("CLAIRE-GRAND-ROND-PLEIN");
    connect(CLAIRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, [=]() {
            CLAIRE_GRAND_ROND_PLEIN->setStyleSheet("background-color: green;");
        });
    CLAIRE_GRAND_ROND_PLEIN->installEventFilter(this);


    QPushButton *CLAIRE_GRAND_CARRE_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(1, 1, 48, 48);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_GRAND_CARRE_TROU->setIcon(QIcon(pix));
    CLAIRE_GRAND_CARRE_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_CARRE_TROU);
    connect(CLAIRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    CLAIRE_GRAND_CARRE_TROU->setObjectName("CLAIRE-GRAND-CARRE-TROU");
    connect(CLAIRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, [=]() {
            CLAIRE_GRAND_CARRE_TROU->setStyleSheet("background-color: green;");
        });
    CLAIRE_GRAND_CARRE_TROU->installEventFilter(this);


    QPushButton *CLAIRE_GRAND_CARRE_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(1, 1, 48, 48);
    CLAIRE_GRAND_CARRE_PLEIN->setIcon(QIcon(pix));
    CLAIRE_GRAND_CARRE_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_CARRE_PLEIN);
    connect(CLAIRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    CLAIRE_GRAND_CARRE_PLEIN->setObjectName("CLAIRE-GRAND-CARRE-PLEIN");
    connect(CLAIRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, [=]() {
            CLAIRE_GRAND_CARRE_PLEIN->setStyleSheet("background-color: green;");
        });
    CLAIRE_GRAND_CARRE_PLEIN->installEventFilter(this);

    // dessins de couleur sombre
    // initialisation d'un nouveau
    QPixmap pix2(50, 50);
    pix2.fill(Qt::transparent);
    QPainter painter2(&pix2);
    painter2.setPen(QColor(Qt::blue));
    painter2.setBrush(QColor(251,251,251));


    QPushButton *SOMBRE_PETIT_ROND_TROU = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawEllipse(14, 14, 22, 22);
    painter2.setBrush(QColor(253, 245, 172));
    painter2.drawEllipse(23, 23, 4, 4);
    SOMBRE_PETIT_ROND_TROU->setIcon(QIcon(pix2));
    SOMBRE_PETIT_ROND_TROU->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_PETIT_ROND_TROU);
    connect(SOMBRE_PETIT_ROND_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_PETIT_ROND_TROU->setObjectName("SOMBRE-PETIT-ROND-TROU");
    connect(SOMBRE_PETIT_ROND_TROU, &QPushButton::clicked, this, [=]() {
            SOMBRE_PETIT_ROND_TROU->setStyleSheet("background-color: green;");
        });
    SOMBRE_PETIT_ROND_TROU->installEventFilter(this);

    QPushButton *SOMBRE_PETIT_ROND_PLEIN = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawEllipse(14, 14, 22, 22);
    SOMBRE_PETIT_ROND_PLEIN->setIcon(QIcon(pix2));
    SOMBRE_PETIT_ROND_PLEIN->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_PETIT_ROND_PLEIN);
    connect(SOMBRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_PETIT_ROND_PLEIN->setObjectName("SOMBRE-PETIT-ROND-PLEIN");
    connect(SOMBRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, [=]() {
            SOMBRE_PETIT_ROND_PLEIN->setStyleSheet("background-color: green;");
        });
    SOMBRE_PETIT_ROND_PLEIN->installEventFilter(this);
