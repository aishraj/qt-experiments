#include "headerViewer.h"

#include <QtCore>

headerViewer::headerViewer()
{
 QNetworkAccessManager *manager = new QNetworkAccessManager;
 connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(output(QNetworkReply*)));
 manager->head(QNetworkRequest(QUrl("http://www.example.org")));
}

headerViewer::~headerViewer()
{}

void headerViewer::output(QNetworkReply* reply)
{
  QList<QByteArray> headerList = reply->rawHeaderList();
  for(int i = 0; i< headerList.size(); ++i){
    QString str(headerList[i].constData());
    qDebug()<< str;
  }
}

#include "headerViewer.moc"
