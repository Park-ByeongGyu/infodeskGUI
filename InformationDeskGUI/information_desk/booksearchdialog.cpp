#include "booksearchdialog.h"
#include "ui_booksearchdialog.h"
#include "bookinfolocation.h"
#include <QStandardItem>
#include <QVBoxLayout>
#include "buttonDelegate.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>


BookSearchDialog::BookSearchDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::BookSearchDialog), model(new QStandardItemModel(this)), searchText("")
{
    ui->setupUi(this);  // 여기서 setupUi 사용

    //검색창 설정
    ui->bookSearchWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->bookSearchWindow->setLineWrapMode(QTextEdit::NoWrap);
    ui->pushButton->setFlat(true);


    //검색결과 창
    ui->bookInfoTable->setMinimumSize(400, 100);  // 최소 크기
    ui->bookInfoTable->horizontalHeader()->setStretchLastSection(true); // 마지막 컬럼 자동 늘리기

    //NetworkManager 생성
    manager = new QNetworkAccessManager(this);



    setupTable();
    //loadData();
}

BookSearchDialog::~BookSearchDialog()
{
    delete ui;
}

void BookSearchDialog::setupTable()
{
    model->setHorizontalHeaderLabels({"ISBN","도서명", "저자", "출판사","위치","대출"});
    ui->bookInfoTable->setModel(model);
    ui->bookInfoTable->verticalHeader()->setVisible(false); //인덱스 삭제
    ui->bookInfoTable->setSortingEnabled(true); // 정렬 가능


    //위치 버튼
    ButtonDelegate* delegatLOC = new ButtonDelegate(this);
    ui->bookInfoTable->setItemDelegateForColumn(4, delegatLOC);
    connect(delegatLOC, &ButtonDelegate::buttonClicked, this, [this](int row){
        QString isbn = model->item(row, 0)->text();

        QString urlString = QString("http://127.0.0.1:8000/infodesk/books/%1").arg(isbn);
        QNetworkRequest request((QUrl(urlString)));
        request.setRawHeader("accept", "application/json");

        QNetworkReply* reply = manager->get(request);
        connect(reply, &QNetworkReply::finished, this, [this, reply](){
            if(reply->error() == QNetworkReply::NoError){
                QByteArray responseData = reply->readAll();
                QJsonDocument doc = QJsonDocument::fromJson(responseData);

                if(doc.isObject()){
                    QJsonObject obj = doc.object();

                    QString detail = QString(
                                         "위치명: %1\n타입: %2\n구역: %3\n층: %4")
                                         .arg(obj["locationName"].toString())
                                         .arg(obj["locType"].toString())
                                         .arg(obj["zoneName"].toString())
                                         .arg(obj["floor"].toString());

                    BookInfoLocation dlg(this);
                    dlg.setText(detail);   // 여기서 BookInfoLocation에 넣어줌
                    dlg.exec();
                }
            } else {
                qDebug() << "HTTP 요청 오류:" << reply->errorString();
            }
            reply->deleteLater();
        });
    });



    //대출 버튼
    ButtonDelegate* delegate1LOAN = new ButtonDelegate(this);
    ui->bookInfoTable->setItemDelegateForColumn(5, delegate1LOAN);
    connect(delegate1LOAN, &ButtonDelegate::buttonClicked, this, [](int row){
        qDebug() << "Button clicked on row:" << row;
    });
}



void BookSearchDialog::on_searchBtn_clicked() // 검색 버튼
{
    QString encodeKeyword = QUrl::toPercentEncoding(searchText);
    QString urlString = QString("http://127.0.0.1:8000/infodesk/books?keyword=%1&page=1&per_page=5")
                            .arg(encodeKeyword);

    QUrl url(urlString);

    QNetworkRequest request(url);
    request.setRawHeader("accept", "application/json");

    QNetworkReply* reply = manager->get(request);

    // 응답 처리
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {

        if(reply->error() == QNetworkReply::NoError){
            QByteArray responseData = reply->readAll();

            // JSON 파싱
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            if(doc.isObject()){ // 최상위가 객체
                QJsonObject rootObj = doc.object();

                if(rootObj.contains("result") && rootObj["result"].isArray()){
                    QJsonArray array = rootObj["result"].toArray();

                    // 기존 테이블 초기화
                    model->removeRows(0, model->rowCount());

                    // JSON → 테이블 반영
                    for(const QJsonValue &val : array){
                        QJsonObject obj = val.toObject();
                        QList<QStandardItem*> rowItems;
                        rowItems.append(new QStandardItem(obj["isbn"].toString()));
                        rowItems.append(new QStandardItem(obj["title"].toString()));
                        rowItems.append(new QStandardItem(obj["author"].toString()));
                        rowItems.append(new QStandardItem(obj["publisher"].toString()));
                        rowItems.append(new QStandardItem(obj["status"].toString()));
                        model->appendRow(rowItems);
                    }

                    ui->bookInfoTable->resizeColumnsToContents();
                }
            }
        } else {
            qDebug() << "HTTP 요청 오류:" << reply->errorString();
        }

        reply->deleteLater();
    });
}



void BookSearchDialog::on_bookSearchWindow_textChanged()// 검색창 속성 설정
{
    searchText = ui->bookSearchWindow->toPlainText();
    ui->searchBtn->setEnabled(!searchText.isEmpty());

}

