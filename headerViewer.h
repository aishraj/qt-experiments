#ifndef headerViewer_H
#define headerViewer_H

#include <QtCore/QObject>

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
