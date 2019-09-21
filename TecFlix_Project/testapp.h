#ifndef TESTAPP_H
#define TESTAPP_H


class testapp
{
public:
    testapp();
};

#endif // TESTAPP_H

#include <QtGui/QApplication>

#include "testapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testApp w;
    w.show();
    return app.exec();
}
