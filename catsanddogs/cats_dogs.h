#ifndef CATS_DOGS_H
#define CATS_DOGS_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Cats_Dogs; }
QT_END_NAMESPACE

/// drdgddctdf
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
    void on_pushButton_3_clicked();
    void ButtonClicked();
    void ComputerSlot();

    void on_pushButton_4_clicked();

private:
    Ui::Cats_Dogs *ui;
    void Interface();
    void ChangeButton(int num);
    void ConfTabWidget();
    void ClickButton(int row, int colum, QString style);
    void ConfInitialButtons();
    void InitialButtons();
    void Start();
    void LockPlayer();
    void ComputerMove();
    void Check();
    void GameOver();


    char GameField[5][5] = {
             {'-','-','-','-','-'},
             {'-','-','-','-','-'},
             {'-','-','-','-','-'},
             {'-','-','-','-','-'},
             {'-','-','-','-','-'},

    };
    char player = 'D';
    int progress = 0;
    bool GameStart = false;
    bool PlayerLocked = true;
    QTimer *timer;
    bool stop;
    char winner;

};
#endif // CATS_DOGS_H
