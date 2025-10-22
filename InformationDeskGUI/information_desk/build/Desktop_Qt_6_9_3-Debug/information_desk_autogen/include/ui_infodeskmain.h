/********************************************************************************
** Form generated from reading UI file 'infodeskmain.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODESKMAIN_H
#define UI_INFODESKMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoDeskMain
{
public:
    QWidget *centralwidget;
    QPushButton *book_search_btn;
    QPushButton *loan_books_btn;
    QPushButton *book_pickup_btn;
    QPushButton *seat_reservation_btn;
    QLabel *title_lb;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InfoDeskMain)
    {
        if (InfoDeskMain->objectName().isEmpty())
            InfoDeskMain->setObjectName("InfoDeskMain");
        InfoDeskMain->resize(627, 631);
        centralwidget = new QWidget(InfoDeskMain);
        centralwidget->setObjectName("centralwidget");
        book_search_btn = new QPushButton(centralwidget);
        book_search_btn->setObjectName("book_search_btn");
        book_search_btn->setGeometry(QRect(70, 350, 141, 91));
        book_search_btn->setStyleSheet(QString::fromUtf8("border: 2px solid #3498db;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"background-color: #ecf0f1;\n"
"font-size: 14pt;\n"
""));
        loan_books_btn = new QPushButton(centralwidget);
        loan_books_btn->setObjectName("loan_books_btn");
        loan_books_btn->setGeometry(QRect(420, 350, 141, 91));
        loan_books_btn->setStyleSheet(QString::fromUtf8("border: 2px solid #3498db;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"background-color: #ecf0f1;\n"
"font-size: 14pt;\n"
""));
        book_pickup_btn = new QPushButton(centralwidget);
        book_pickup_btn->setObjectName("book_pickup_btn");
        book_pickup_btn->setGeometry(QRect(70, 490, 141, 91));
        book_pickup_btn->setStyleSheet(QString::fromUtf8("border: 2px solid #3498db;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"background-color: #ecf0f1;\n"
"font-size: 14pt;\n"
""));
        seat_reservation_btn = new QPushButton(centralwidget);
        seat_reservation_btn->setObjectName("seat_reservation_btn");
        seat_reservation_btn->setGeometry(QRect(420, 490, 141, 91));
        seat_reservation_btn->setStyleSheet(QString::fromUtf8("border: 2px solid #3498db;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"background-color: #ecf0f1;\n"
"font-size: 14pt;\n"
""));
        title_lb = new QLabel(centralwidget);
        title_lb->setObjectName("title_lb");
        title_lb->setGeometry(QRect(70, 60, 491, 251));
        title_lb->setStyleSheet(QString::fromUtf8("border: 2px solid #3498db;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"background-color: #ecf0f1;\n"
"font-size: 14pt;\n"
""));
        title_lb->setTextFormat(Qt::TextFormat::AutoText);
        title_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        InfoDeskMain->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InfoDeskMain);
        statusbar->setObjectName("statusbar");
        InfoDeskMain->setStatusBar(statusbar);

        retranslateUi(InfoDeskMain);

        QMetaObject::connectSlotsByName(InfoDeskMain);
    } // setupUi

    void retranslateUi(QMainWindow *InfoDeskMain)
    {
        InfoDeskMain->setWindowTitle(QCoreApplication::translate("InfoDeskMain", "InfoDeskMain", nullptr));
        book_search_btn->setText(QCoreApplication::translate("InfoDeskMain", "\353\217\204\354\204\234 \354\241\260\355\232\214", nullptr));
        loan_books_btn->setText(QCoreApplication::translate("InfoDeskMain", "\353\217\204\354\204\234 \353\214\200\354\266\234", nullptr));
        book_pickup_btn->setText(QCoreApplication::translate("InfoDeskMain", "\353\263\264\352\264\200 \353\217\204\354\204\234 \n"
" \352\260\200\354\240\270\352\260\200\352\270\260", nullptr));
        seat_reservation_btn->setText(QCoreApplication::translate("InfoDeskMain", "\354\242\214\354\204\235 \354\230\210\354\225\275", nullptr));
        title_lb->setText(QCoreApplication::translate("InfoDeskMain", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\354\212\244\353\247\210\355\212\270 \353\217\204\354\204\234\352\264\200\354\227\220 </span></p><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\354\230\244\354\213\240 \352\262\203\354\235\204 \355\231\230\354\230\201\355\225\251\353\213\210\353\213\244.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoDeskMain: public Ui_InfoDeskMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODESKMAIN_H
