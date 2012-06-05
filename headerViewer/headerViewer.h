#ifndef headerViewer_H
#define headerViewer_H

#include <QtCore/QObject>
#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class headerViewer : public QObject
{
Q_OBJECT
public:
    headerViewer();
    virtual ~headerViewer();
public slots:
    void output(QNetworkReply*);

};

#endif // headerViewer_H
