#include "headerViewer.h"

#include <QtCore>
#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

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
  for(int i = 0; i< headerList.size(); ++i){
    QString str(headerList[i].constData());
    qDebug()<< str;
  }
}

#include "headerViewer.moc"
