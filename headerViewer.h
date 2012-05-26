#ifndef headerViewer_H
#define headerViewer_H

#include <QtCore/QObject>
#include <qnetworkaccessmanager.h>

class headerViewer : public QObject
{
Q_OBJECT
public:
    headerViewer();
    virtual ~headerViewer();
public slots:
    void output(QList<QByteArray>);

};

#endif // headerViewer_H
