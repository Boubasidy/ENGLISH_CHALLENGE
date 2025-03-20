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