#include "cats_dogs.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cats_dogs w;
    w.show();
    return a.exec();
}
