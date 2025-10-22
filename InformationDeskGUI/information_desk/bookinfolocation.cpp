#include "bookinfolocation.h"
#include "ui_bookinfolocation.h"

BookInfoLocation::BookInfoLocation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookInfoLocation)
{
    ui->setupUi(this);
}

BookInfoLocation::~BookInfoLocation()
{
    delete ui;
}
void BookInfoLocation::setText(const QString &text)
{
    ui->textEdit->setPlainText(text); // textEdit 이름에 맞게
}
