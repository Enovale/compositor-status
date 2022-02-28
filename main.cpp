#include <QCoreApplication>
#include <QApplication>
#include <qdebug.h>
#include "CompositorNotifier.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    new CompositorNotifier();
    return app.exec();
}