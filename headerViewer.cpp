#include "headerViewer.h"

#include <QtCore>

headerViewer::headerViewer()
{
 QNetworkAccessManager *manager = new QNetworkAccessManager;
 connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(output(QNetworkReply*)));
 manager->head(QNetworkRequest(QUrl("http://download.services.openoffice.org/files/stable/3.3.0/OOo-SDK_3.3.0_Linux_x86-64_install-deb_en-US.tar.gz")));
}

headerViewer::~headerViewer()
{}

void headerViewer::output(QNetworkReply* reply)
{
  QList<QByteArray> headerList = reply->rawHeaderList();
  QList<QByteArray> headerValues;
  for(int i = 0; i< headerList.size(); ++i)
  {
    //QString str(headerList[i].constData());
    //qDebug()<< str;
    headerValues.push_back(reply->rawHeader(headerList[i].constData()));
  }
  for ( int i = 0; i < headerList.size(); ++i)
  {
   QString headerName(headerList[i].constData());
   QString headerVal(headerValues[i].constData());
   qDebug() << headerName << "\t" << headerVal<<"\n";
  }
    
}

#include "headerViewer.moc"
