/********************************************************************************
** Form generated from reading UI file 'booksearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSEARCHDIALOG_H
#define UI_BOOKSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BookSearchDialog
{
public:
    QPushButton *pushButton;
    QTextEdit *bookSearchWindow;
    QTableView *bookInfoTable;
    QPushButton *searchBtn;

    void setupUi(QDialog *BookSearchDialog)
    {
        if (BookSearchDialog->objectName().isEmpty())
            BookSearchDialog->setObjectName("BookSearchDialog");
        BookSearchDialog->resize(619, 703);
        pushButton = new QPushButton(BookSearchDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 81, 81));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setIconSize(QSize(64, 64));
        pushButton->setFlat(true);
        bookSearchWindow = new QTextEdit(BookSearchDialog);
        bookSearchWindow->setObjectName("bookSearchWindow");
        bookSearchWindow->setGeometry(QRect(120, 20, 401, 61));
        bookSearchWindow->setStyleSheet(QString::fromUtf8("font: 500 26pt \"Ubuntu Sans\";"));
        bookInfoTable = new QTableView(BookSearchDialog);
        bookInfoTable->setObjectName("bookInfoTable");
        bookInfoTable->setGeometry(QRect(20, 100, 581, 571));
        searchBtn = new QPushButton(BookSearchDialog);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setEnabled(false);
        searchBtn->setGeometry(QRect(520, 20, 81, 61));

        retranslateUi(BookSearchDialog);

        QMetaObject::connectSlotsByName(BookSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *BookSearchDialog)
    {
        BookSearchDialog->setWindowTitle(QCoreApplication::translate("BookSearchDialog", "Dialog", nullptr));
        pushButton->setText(QString());
        bookSearchWindow->setDocumentTitle(QString());
        searchBtn->setText(QCoreApplication::translate("BookSearchDialog", "\352\262\200\354\203\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookSearchDialog: public Ui_BookSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSEARCHDIALOG_H
