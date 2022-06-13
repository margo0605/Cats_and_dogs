#ifndef CATS_DOGS_H
#define CATS_DOGS_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Cats_Dogs; }
QT_END_NAMESPACE

class Cats_Dogs : public QMainWindow
{
    Q_OBJECT

public:
    Cats_Dogs(QWidget *parent = nullptr);
    ~Cats_Dogs();


protected:
    void paintEvent(QPaintEvent *event);


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Cats_Dogs *ui;
    void Interface();
    void ChangeButton(int num);
};
#endif // CATS_DOGS_H
