#ifndef headerViewer_H
#define headerViewer_H

#include <QtCore/QObject>

class headerViewer : public QObject
{
Q_OBJECT
public:
    headerViewer();
    virtual ~headerViewer();
private slots:
    void output();
};

#endif // headerViewer_H
