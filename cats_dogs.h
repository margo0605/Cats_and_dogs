#ifndef CATS_DOGS_H
#define CATS_DOGS_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class cats_dogs; }
QT_END_NAMESPACE

class cats_dogs : public QMainWindow
{
    Q_OBJECT

public:
    cats_dogs(QWidget *parent = nullptr);
    ~cats_dogs();
protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

private:
    Ui::cats_dogs *ui;
    void Interface();
    void ChangeButton(int num);
};
#endif // CATS_DOGS_H
