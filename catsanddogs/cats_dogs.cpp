#include "cats_dogs.h"
#include "ui_cats_dogs.h"
#include <QTabBar>
#include <needhelp.h>
#include <QStyleOption>
#include <QDebug>
#include <QFontDatabase>
#include <QGridLayout>
#include <time.h>

Cats_Dogs::Cats_Dogs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cats_Dogs)
{
    ui->setupUi(this);

    ConfTabWidget();
    Interface();
    ConfInitialButtons();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cats_Dogs::ComputerSlot );

    int id = QFontDatabase::addApplicationFont(":/fonts/After Cheret Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << family;
    int i = QFontDatabase::addApplicationFont(":/fonts/Dynasty.ttf");
    QString fam = QFontDatabase::applicationFontFamilies(i).at(0);
    qDebug() << fam;
}

Cats_Dogs::~Cats_Dogs()
{
    delete ui;
}

void Cats_Dogs::paintEvent(QPaintEvent *event)
{
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
     QWidget::paintEvent(event);
}

void Cats_Dogs::Interface()
{
    this->setStyleSheet(NEEDHELP::Cats_dogsStyle());
    ui->pushButton_3->setStyleSheet(NEEDHELP::ButtonEditor());
    ui->pushButton_4->setStyleSheet(NEEDHELP::ButtonEditor());
    ui->label->setStyleSheet(NEEDHELP::LabelEditor());
    ui->pushButton->setStyleSheet(NEEDHELP::RButtonEditor());
    ui->pushButton_2->setStyleSheet(NEEDHELP::LButtonActEditor());
    ui->label_3->setStyleSheet(NEEDHELP::Label3Editor());
    ui->tabWidget->setStyleSheet(NEEDHELP::TabButtons());
    ui->tab_2->setStyleSheet(NEEDHELP::TabButtons());

    InitialButtons();
    ui->label_2->setText("");
    ui->label_2->setStyleSheet(NEEDHELP::MessagePlay());


}

void Cats_Dogs::ChangeButton(int num)
{
    if (num == 1){
         ui->pushButton_2->setStyleSheet(NEEDHELP::LButtonActEditor());
         ui->pushButton->setStyleSheet(NEEDHELP::RButtonEditor());
    }else{
         ui->pushButton_2->setStyleSheet(NEEDHELP::LButtonEditor());
         ui->pushButton->setStyleSheet(NEEDHELP::RButtonActEditor());
    }
}

void Cats_Dogs::ConfTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setMaximumHeight(500);
    ui->tabWidget->setCurrentIndex(1);
}

void Cats_Dogs::ClickButton(int row, int colum, QString style)
{
     QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab_2->layout());
     QPushButton *btn = qobject_cast <QPushButton*> (grid ->itemAtPosition(row,colum)->widget());
     btn->setStyleSheet(style);
}

void Cats_Dogs::ConfInitialButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab_2->layout());
    for(int row = 0; row < 5; row++){
        for(int column = 0; column < 5; column++){
            QPushButton *btn = qobject_cast <QPushButton*> (grid ->itemAtPosition(row,column)->widget());
            btn->setProperty("row", row);
            btn->setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &Cats_Dogs::ButtonClicked);
            }
        }
}

void Cats_Dogs::InitialButtons()
{
    QString style = NEEDHELP::BeforeGame();
    for(int row = 0; row < 5; row++){
        for(int column = 0; column < 5; column++){
            ClickButton(row, column, style);
        }
    }
}

void Cats_Dogs::Start()
{
    InitialButtons();
    for (int r=0;r<5;r++){
        for(int c=0; c<5;c++){
            GameField[r][c] = '-';
        }
    }
    progress = 0;
    GameStart = true;
    stop = false;
    if(player != 'D')
        ComputerMove();

}

void Cats_Dogs::LockPlayer()
{
    if(player == 'D'){
        PlayerLocked = false;
    }else{
        PlayerLocked = true;
    }
}







void Cats_Dogs::on_pushButton_2_clicked()  //псы
{
    ChangeButton(1);
    player = 'D';
}


void Cats_Dogs::on_pushButton_clicked()
{
    ChangeButton(2);
    player = 'C';
}

void Cats_Dogs::on_pushButton_3_clicked()
{
    if(GameStart){
        PlayerLocked = true;
        ui->pushButton_3->setText("Play");
        ui->pushButton_3->setStyleSheet(NEEDHELP::ButtonEditor());
        ui->pushButton_2-> setDisabled(false);
        ui->pushButton-> setDisabled(false);
        GameStart = false;
        ui->label_2->setText("You lost!");
        ui->label_2->setStyleSheet(NEEDHELP::MessageLose());

    }else{
         ui->label_2->setText("Let's go!");
         ui->label_2->setStyleSheet(NEEDHELP::MessagePlay());
         Start();
         LockPlayer();
         ui->pushButton_3->setStyleSheet(NEEDHELP::ButtonEditor());
         ui->pushButton_3->setText("I surrender...");
         ui->pushButton_2-> setDisabled(true);
         ui->pushButton-> setDisabled(true);

    }


}

void Cats_Dogs::ButtonClicked()
{
    if(!PlayerLocked) {
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int row = btn->property("row").toInt();
        int column = btn->property("column").toInt();
        QString style;
        if (player == 'D'){
            style = NEEDHELP::DogsPlay();
            GameField[row][column] = 'D';
        }else{
            style = NEEDHELP::CatsPlay();
            GameField[row][column] = 'C';
        }
        ClickButton(row,column,style);
        PlayerLocked = true;
        progress++;
        Check();
        GameOver();
        ComputerMove();
    }
}

void Cats_Dogs::ComputerMove()
{
    if(stop)
        return;
    srand(time(0));
    int index = arc4random()%4 ;
    QStringList list = {"My move!", "Hm...complicated", "Well,well,well...", "Let me think!"};
    ui->label_2->setText(list.at(index));
    timer->start(1000);
}

void Cats_Dogs::Check()
{
     winner = '-';
     char symbols[2] = {'D','C'};
     for (int i = 0; i < 4; i++) {
         for (int row = 0; row < 5; row++) {
             if((GameField[row][0]==symbols[i])and(GameField[row][1]==symbols[i])and(GameField[row][2]==symbols[i])and(GameField[row][3]==symbols[i])){
                 stop = true;
                 winner = symbols[i];
                 return;
             }
         }
         for (int row = 0; row < 5; row++) {
              if((GameField[row][1]==symbols[i])and(GameField[row][2]==symbols[i])and(GameField[row][3]==symbols[i])and(GameField[row][4]==symbols[i])){
                 stop = true;
                 winner = symbols[i];
                 return;
               }
            }
         for (int column = 0; column < 5; column++){
              if((GameField[0][column]==symbols[i])and(GameField[1][column]==symbols[i])and(GameField[2][column]==symbols[i])and(GameField[3][column]==symbols[i])){
                  stop = true;
                  winner = symbols[i];
                  return;
              }
         }
          for (int column = 0; column < 5; column++){
              if((GameField[1][column]==symbols[i])and(GameField[2][column]==symbols[i])and(GameField[3][column]==symbols[i])and(GameField[4][column]==symbols[i])){
                  stop = true;
                  winner = symbols[i];
                  return;
         }

     }
              if((GameField[0][0]==symbols[i])and(GameField[1][1]==symbols[i])and(GameField[2][2]==symbols[i])and(GameField[3][3]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }
              if((GameField[1][1]==symbols[i])and(GameField[2][2]==symbols[i])and(GameField[3][3]==symbols[i])and(GameField[4][4]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }
              if((GameField[0][4]==symbols[i])and(GameField[1][3]==symbols[i])and(GameField[2][2]==symbols[i])and(GameField[3][1]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }

              if((GameField[1][3]==symbols[i])and(GameField[2][2]==symbols[i])and(GameField[3][1]==symbols[i])and(GameField[4][0]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }

              if((GameField[1][0]==symbols[i])and(GameField[2][1]==symbols[i])and(GameField[3][2]==symbols[i])and(GameField[4][3]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }

              if((GameField[0][1]==symbols[i])and(GameField[1][2]==symbols[i])and(GameField[2][3]==symbols[i])and(GameField[3][4]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }

              if((GameField[0][3]==symbols[i])and(GameField[1][2]==symbols[i])and(GameField[2][1]==symbols[i])and(GameField[3][0]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }
              if((GameField[1][4]==symbols[i])and(GameField[2][3]==symbols[i])and(GameField[3][2]==symbols[i])and(GameField[4][1]==symbols[i])) {
                  stop = true;
                  winner = symbols[i];
                  return;
              }
            }
     if(progress == 25) {
         stop = true;
     }
         }



void Cats_Dogs::GameOver()
{
    PlayerLocked = true;
    if(stop) {
        if(winner == player) {
            ui->label_2->setText("Victory!");
            ui->label_2->setStyleSheet(NEEDHELP::MessageWin());
        }else if(winner == '-') {
            ui->label_2->setText("Draw!");
        }else{
            ui->label_2->setText("Defeat(");
            ui->label_2->setStyleSheet(NEEDHELP::MessageLose());

        }
        PlayerLocked = true;
        ui->pushButton_3->setText("Play");
        ui->pushButton_3->setStyleSheet(NEEDHELP::ButtonEditor());
        ui->pushButton_2->setDisabled(false);
        ui->pushButton->setDisabled(false);
        GameStart = false;

    }
}


void Cats_Dogs::ComputerSlot() {
    char comp;
    QString style;
    if (player == 'D') {
        comp = 'C';
        style = NEEDHELP::CatsPlay();
    }else{
        comp = 'D';
        style = NEEDHELP::DogsPlay();
    }
    timer->stop();
        while(true) {
            int row = arc4random()%5;
            int column = arc4random()%5;
                if(GameField[row][column] == '-'){
                GameField[row][column] = comp;
                ClickButton(row, column, style);
                ui->label_2->setText("Your turn!");
                progress++;
                Check();
                GameOver();
                PlayerLocked = false;
                break;
                }
            }

}


void Cats_Dogs::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

