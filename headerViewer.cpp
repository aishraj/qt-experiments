#include "headerViewer.h"

#include <QTimer>
#include <iostream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include <QByteArray>

headerViewer::headerViewer()
{
 QNetworkAccessManager manager;
 QNetworkRequest request;
 request.setUrl(QUrl("http://www.example.org"));
 QNetworkReply *reply = manager.head(request);
 QList<QByteArray> headerList = reply->rawHeaderList();
 connect(reply,SIGNAL(finished()),this,SLOT(output(headerList)));
}

headerViewer::~headerViewer()
{}

void headerViewer::output(QList< QByteArray > headerList)
{
  for(int i=0; i<headerList.size(); ++i){
    QString str(headerList[i].constData());
    qDebug()<< str;
  }
}

#include "headerViewer.moc"
