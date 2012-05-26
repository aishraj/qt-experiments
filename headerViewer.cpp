#include "headerViewer.h"

#include <QTimer>
#include <iostream>

headerViewer::headerViewer()
{
    QTimer* timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), SLOT(output()) );
    timer->start( 1000 );
}

headerViewer::~headerViewer()
{}

void headerViewer::output()
{
    std::cout << "Hello World!" << std::endl;
}

#include "headerViewer.moc"
