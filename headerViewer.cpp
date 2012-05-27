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
  const QList<QNetworkReply::RawHeaderPair> headers = reply->rawHeaderPairs();
  foreach(const QNetworkReply::RawHeaderPair headerInfo, headers)
  {
      qDebug() << headerInfo.first << ":" << headerInfo.second;
  }
  exit(0);
    
}

#include "headerViewer.moc"
