/********************************************************************************
** Form generated from reading UI file 'bookinfolocation.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFOLOCATION_H
#define UI_BOOKINFOLOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BookInfoLocation
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *BookInfoLocation)
    {
        if (BookInfoLocation->objectName().isEmpty())
            BookInfoLocation->setObjectName("BookInfoLocation");
        BookInfoLocation->resize(476, 355);
        textEdit = new QTextEdit(BookInfoLocation);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(140, 80, 211, 191));

        retranslateUi(BookInfoLocation);

        QMetaObject::connectSlotsByName(BookInfoLocation);
    } // setupUi

    void retranslateUi(QDialog *BookInfoLocation)
    {
        BookInfoLocation->setWindowTitle(QCoreApplication::translate("BookInfoLocation", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookInfoLocation: public Ui_BookInfoLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFOLOCATION_H
