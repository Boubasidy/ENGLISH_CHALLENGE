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

    QPushButton *SOMBRE_PETIT_CARRE_TROU = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawRect(14, 14, 22, 22);
    painter2.setBrush(QColor(253, 245, 172));
    painter2.drawEllipse(23, 23, 4, 4);
    SOMBRE_PETIT_CARRE_TROU->setIcon(QIcon(pix2));
    SOMBRE_PETIT_CARRE_TROU->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_PETIT_CARRE_TROU);
    connect(SOMBRE_PETIT_CARRE_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_PETIT_CARRE_TROU->setObjectName("SOMBRE-PETIT-CARRE-TROU");
    connect(SOMBRE_PETIT_CARRE_TROU, &QPushButton::clicked, this, [=]() {
            SOMBRE_PETIT_CARRE_TROU->setStyleSheet("background-color: green;");
        });
    SOMBRE_PETIT_CARRE_TROU->installEventFilter(this);

    QPushButton *SOMBRE_PETIT_CARRE_PLEIN = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawRect(14, 14, 22, 22);
    SOMBRE_PETIT_CARRE_PLEIN->setIcon(QIcon(pix2));
    SOMBRE_PETIT_CARRE_PLEIN->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_PETIT_CARRE_PLEIN);
    connect(SOMBRE_PETIT_CARRE_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_PETIT_CARRE_PLEIN->setObjectName("SOMBRE-PETIT-CARRE-PLEIN");
    connect(SOMBRE_PETIT_CARRE_PLEIN, &QPushButton::clicked, this, [=]() {
            SOMBRE_PETIT_CARRE_PLEIN->setStyleSheet("background-color: green;");
        });
    SOMBRE_PETIT_CARRE_PLEIN->installEventFilter(this);

    QPushButton *SOMBRE_GRAND_ROND_TROU = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawEllipse(1, 1, 48, 48);
    painter2.setBrush(QColor(253, 245, 172));
    painter2.drawEllipse(23, 23, 4, 4);
    SOMBRE_GRAND_ROND_TROU->setIcon(QIcon(pix2));
    SOMBRE_GRAND_ROND_TROU->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_GRAND_ROND_TROU);
    connect(SOMBRE_GRAND_ROND_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_GRAND_ROND_TROU->setObjectName("SOMBRE-GRAND-ROND-TROU");
    connect(SOMBRE_GRAND_ROND_TROU, &QPushButton::clicked, this, [=]() {
            SOMBRE_GRAND_ROND_TROU->setStyleSheet("background-color: green;");
        });
    SOMBRE_GRAND_ROND_TROU->installEventFilter(this);



    QPushButton *SOMBRE_GRAND_ROND_PLEIN = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawEllipse(1, 1, 48, 48);
    SOMBRE_GRAND_ROND_PLEIN->setIcon(QIcon(pix2));
    SOMBRE_GRAND_ROND_PLEIN->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_GRAND_ROND_PLEIN);
    connect(SOMBRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_GRAND_ROND_PLEIN->setObjectName("SOMBRE-GRAND-ROND-PLEIN");
    connect(SOMBRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, [=]() {
            SOMBRE_GRAND_ROND_PLEIN->setStyleSheet("background-color: green;");
        });
    SOMBRE_GRAND_ROND_PLEIN->installEventFilter(this);


    QPushButton *SOMBRE_GRAND_CARRE_TROU = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawRect(1, 1, 48, 48);
    painter2.setBrush(QColor(253, 245, 172));
    painter2.drawEllipse(23, 23, 4, 4);
    SOMBRE_GRAND_CARRE_TROU->setIcon(QIcon(pix2));
    SOMBRE_GRAND_CARRE_TROU->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_GRAND_CARRE_TROU);
    connect(SOMBRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_GRAND_CARRE_TROU->setObjectName("SOMBRE-GRAND-CARRE-TROU");
    connect(SOMBRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, [=]() {
            SOMBRE_GRAND_CARRE_TROU->setStyleSheet("background-color: green;");
        });
    SOMBRE_GRAND_CARRE_TROU->installEventFilter(this);



    QPushButton *SOMBRE_GRAND_CARRE_PLEIN = new QPushButton;
    painter2.setBrush(QColor(51, 25, 0));
    painter2.drawRect(1, 1, 48, 48);
    SOMBRE_GRAND_CARRE_PLEIN->setIcon(QIcon(pix2));
    SOMBRE_GRAND_CARRE_PLEIN->setIconSize(pix2.size());
    piecesLayout->addWidget(SOMBRE_GRAND_CARRE_PLEIN);
    connect(SOMBRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, &QuadrantWidget::Choose_Piece);
    SOMBRE_GRAND_CARRE_PLEIN->setObjectName("SOMBRE-GRAND-CARRE-PLEIN");
    connect(SOMBRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, [=]() {
            SOMBRE_GRAND_CARRE_PLEIN->setStyleSheet("background-color: green;");
        });
    SOMBRE_GRAND_CARRE_PLEIN->installEventFilter(this);

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

    footerLabel = new QLabel(QString::fromStdString(_footer));

    mainLayout->addStretch();
    mainLayout->addWidget(statusLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(piecesLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(boardLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(footerLabel);

    statusLabel->setAlignment(Qt::AlignCenter);
    piecesLayout->setAlignment(Qt::AlignCenter);
    boardLayout->setAlignment(Qt::AlignCenter);
    footerLabel->setAlignment(Qt::AlignLeft);
   }

QuadrantWidget::~QuadrantWidget() {}

void QuadrantWidget::Choose_Piece() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        Iconselected = button->icon();
        _footer = button->objectName().toStdString();
        footerLabel->setText(QString::fromStdString(_footer));
    }
}

void QuadrantWidget::Place_Piece(int row, int col) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && !Iconselected.isNull()) {
        button->setIcon(Iconselected);
        button->setStyleSheet("border: none;");
        _column = col;
        _row = row;
        QLabel *his = new QLabel(QString::fromStdString("Joueur "+std::to_string(PlayerNumber)+" a placé "+_footer+" en ("+std::to_string(_row)+","+std::to_string(_column)+")"));
        _Historical_Labels.push_back(his);
        Changement_joueur();
        _status = "Joueur Actif: " + std::to_string(PlayerNumber) + "\nJoueur " + std::to_string((PlayerNumber==1)?2:1) + " doit sélectionner une pièce que le joueur " + std::to_string(PlayerNumber) + " place.";
        statusLabel->setText(QString::fromStdString(_status));
        for (int i = 0; i < piecesLayout->count(); ++i) {
            QLayoutItem* item = piecesLayout->itemAt(i);
            if (item && item->widget() && item->widget()->objectName() == QString::fromStdString(_footer)) {
                piecesLayout->removeItem(item);
                delete item->widget();
                delete item;
                break;
            }
        }
        std::vector<std::vector<std::string>> rowNeighbors;
        std::vector<std::vector<std::string>> colNeighbors;
        std::vector<std::vector<std::string>> diagonal1Neighbors; // Diagonale principale (0,0), (1,1), (2,2), ...
        std::vector<std::vector<std::string>> diagonal2Neighbors;
        if(_Historical_Labels.size() > 1) {
            for (unsigned long i = 0; i < _Historical_Labels.size(); ++i) {
                QLabel* labeltest = _Historical_Labels[i];
                std::string labelText = labeltest->text().toStdString();
                int start = labelText.find("(") + 1;
                std::string coordinates = labelText.substr(start, 3);
                int line = coordinates[0] - '0';
                int column = coordinates[2] - '0';
                std::string characteristics = labelText.substr(18, start - 5 - 18);
                std::vector<std::string> characteristicsList = split(characteristics, '-');

                if (line == row) {
                    rowNeighbors.push_back(characteristicsList);
                }
                if (column == col) {
                    colNeighbors.push_back(characteristicsList);
                }
                if (line == column) {
                    diagonal1Neighbors.push_back(characteristicsList);
                }
                if (line + column == 3) {
                    diagonal2Neighbors.push_back(characteristicsList);
                }
            }
        }
        bool test_completed = false;
        if (rowNeighbors.size() == 4) {
            std::vector<std::string> _List = split(_footer, '-');
            for (auto i : _List) {
                test_completed = true;
                for (auto v : rowNeighbors) {
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        test_completed = false;
                        break;
                    }
                }
                if (test_completed) {
                    QLabel *recup = getHistoricalLabels().back();
                    std::string numwin = recup->text().toStdString();

                    std::string joueurSubstring = "Joueur ";
                    size_t joueurPos = numwin.find(joueurSubstring);

                    if (joueurPos != std::string::npos) {
                        size_t startNumPos = joueurPos + joueurSubstring.length();
                        size_t endNumPos = numwin.find_first_not_of("0123456789", startNumPos);
                        std::string numeroJoueur = numwin.substr(startNumPos, endNumPos - startNumPos);
                        int PlayerNumber = std::stoi(numeroJoueur);
                        QMessageBox::information(this, tr("Partie terminée"), tr("Joueur ") + QString::number(PlayerNumber) + tr(" a gagné"));
                        QLabel *newvainq = new QLabel(QString("FIN de la partie victoire du joueur " + QString::number(PlayerNumber)));
                        _Historical_Labels.push_back(newvainq);
                        std::ofstream outputFile("history.log");
                        if (outputFile.is_open())
                        { for (auto label : _Historical_Labels) { outputFile << label->text().toStdString() << std::endl; }
                            outputFile.close(); }
                    }
                }
            }
        }
        else if (colNeighbors.size() == 4) {
            std::vector<std::string> _List = split(_footer, '-');
            for (auto i : _List) {
                test_completed = true;
                for (auto v : colNeighbors) {
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        test_completed = false;
                        break;
                    }
                }
                if (test_completed) {
                    QLabel *recup = getHistoricalLabels().back();
                    std::string numwin = recup->text().toStdString();

                    std::string joueurSubstring = "Joueur ";
                    size_t joueurPos = numwin.find(joueurSubstring);

                    if (joueurPos != std::string::npos) {
                        size_t startNumPos = joueurPos + joueurSubstring.length();
                        size_t endNumPos = numwin.find_first_not_of("0123456789", startNumPos);
                        std::string numeroJoueur = numwin.substr(startNumPos, endNumPos - startNumPos);
                        int PlayerNumber = std::stoi(numeroJoueur);
                        QMessageBox::information(this, tr("Partie terminée"), tr("Joueur ") + QString::number(PlayerNumber) + tr(" a gagné"));
                        QLabel *newvainq = new QLabel(QString("FIN de la partie victoire du joueur " + QString::number(PlayerNumber)));
                        _Historical_Labels.push_back(newvainq);
                        std::ofstream outputFile("history.log");
                        if (outputFile.is_open())
                        { for (auto label : _Historical_Labels) { outputFile << label->text().toStdString() << std::endl; }
                            outputFile.close(); }
                    }

                }
            }
        }
        else if (diagonal1Neighbors.size() == 4 || diagonal2Neighbors.size() == 4) {
            std::vector<std::string> _List = split(_footer, '-');
            for (auto i : _List) {
                test_completed = true;
                if (diagonal1Neighbors.size() == 4) {
                    for (auto v : diagonal1Neighbors) {
                        auto it = std::find(v.begin(), v.end(), i);
                        if (it == v.end()) {
                            test_completed = false;
                            break;
                        }
                    }
                }
                if (diagonal2Neighbors.size() == 4) {
                    for (auto v : diagonal2Neighbors) {
                        auto it = std::find(v.begin(), v.end(), i);
                        if (it == v.end()) {
                            test_completed = false;
                            break;
                        }
                    }
                }
                if (test_completed) {
                    QLabel *recup = getHistoricalLabels().back();
                    std::string numwin = recup->text().toStdString();
                    std::string joueurSubstring = "Joueur ";
                    size_t joueurPos = numwin.find(joueurSubstring);

                    if (joueurPos != std::string::npos) {
                        size_t startNumPos = joueurPos + joueurSubstring.length();
                        size_t endNumPos = numwin.find_first_not_of("0123456789", startNumPos);
                        std::string numeroJoueur = numwin.substr(startNumPos, endNumPos - startNumPos);
                        int PlayerNumber = std::stoi(numeroJoueur);
                        QMessageBox::information(this, tr("Partie terminée"), tr("Joueur ") + QString::number(PlayerNumber) + tr(" a gagné"));
                        QLabel *newvainq = new QLabel(QString("FIN de la partie victoire du joueur " + QString::number(PlayerNumber)));
                        _Historical_Labels.push_back(newvainq);
                        std::ofstream outputFile("history.log");
                        if (outputFile.is_open())
                        { for (auto label : _Historical_Labels) { outputFile << label->text().toStdString() << std::endl; }
                            outputFile.close(); }
                    }
                }
            }
        }
        else {
            // gestion de la fin de partie
            if ( !test_completed && piecesLayout->count() == 0) {
                   QMessageBox::information(this, tr("Partie terminée"), tr("La partie est terminée. Merci d'avoir joué !"));
                   QLabel *newvainq = new QLabel(QString("FIN de la partie , aucun gagnant "));
                   _Historical_Labels.push_back(newvainq);
                   std::ofstream outputFile("history.log");
                   if (outputFile.is_open())
                   { for (auto label : _Historical_Labels) { outputFile << label->text().toStdString() << std::endl; }
                       outputFile.close(); }


               }


            }
}
//
button->setCheckable(false);

}

bool QuadrantWidget::eventFilter(QObject* obj, QEvent* event){
    if (event->type() == QEvent::HoverEnter) {
        QPushButton* button = qobject_cast<QPushButton*>(obj);
        if (button) {
            button->setStyleSheet("background-color: blue;");
        }
    } else if (event->type() == QEvent::HoverLeave) {
        QPushButton* button = qobject_cast<QPushButton*>(obj);
        if (button) {
            button->setStyleSheet("background-color: green");
        }
    }
    return false;
}


// la fonction est destiné à la géneration du fichier log mais elle n'a pas fonctionné
void QuadrantWidget::writeLabelsToFile(const QString& filename, const std::vector<QLabel*>& labels) {
 QFile file(filename);
 if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
     qDebug() << "Erreur : Impossible d'ouvrir le fichier pour l'écriture.";
     return;
 }
 QTextStream out(&file);
 for (const auto& label : labels) {
     out << label->text() << "\n";
 }
 file.close();
}

void QuadrantWidget::Changement_joueur(){
 PlayerNumber = (PlayerNumber == 1) ? 2 : 1;
}
    