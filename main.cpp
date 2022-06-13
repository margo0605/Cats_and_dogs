#include "cats_dogs.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cats_Dogs w;
    w.show();
    return a.exec();
}
