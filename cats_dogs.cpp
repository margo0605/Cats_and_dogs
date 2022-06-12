#include "cats_dogs.h"
#include "ui_cats_dogs.h"
#include <QTabBar>
#include <needhelp.h>
#include <QStyleOption>
#include <QDebug>
#include <QFontDatabase>

cats_dogs::cats_dogs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cats_dogs)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();                 //прячет виджеты "игра" и "жми!"
    ui->tabWidget->setMaximumHeight(500);
    ui->tabWidget->setCurrentIndex(0);              //переключает на вкладку "игра"
    Interface();
    int id = QFontDatabase::addApplicationFont(":/fonts/After Cheret Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << family;
    int i = QFontDatabase::addApplicationFont(":/fonts/Dynasty.ttf");
    QString fam = QFontDatabase::applicationFontFamilies(i).at(0);
    qDebug() << fam;
}

cats_dogs::~cats_dogs()
{
    delete ui;
}

void cats_dogs::paintEvent(QPaintEvent *event)
{
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
     QWidget::paintEvent(event);
}

void cats_dogs::Interface()
{
 this->setStyleSheet(NEEDHELP::Cats_dogsStyle());
 ui->pushButton_28->setStyleSheet(NEEDHELP::ButtonEditor());
 ui->pushButton_30->setStyleSheet(NEEDHELP::ButtonEditor());
 ui->label->setStyleSheet(NEEDHELP::LabelEditor());
 ui->pushButton_26->setStyleSheet(NEEDHELP::RButtonEditor());
 ui->pushButton_27->setStyleSheet(NEEDHELP::LButtonActEditor());


}

void cats_dogs::ChangeButton(int num)
{
    if (num == 1){
         ui->pushButton_27->setStyleSheet(NEEDHELP::LButtonActEditor());
         ui->pushButton_26->setStyleSheet(NEEDHELP::RButtonEditor());
    }else{
         ui->pushButton_27->setStyleSheet(NEEDHELP::LButtonEditor());
         ui->pushButton_26->setStyleSheet(NEEDHELP::RButtonActEditor());
    }
}


void cats_dogs::on_pushButton_27_clicked()
{
    ChangeButton(1);
}


void cats_dogs::on_pushButton_26_clicked()
{
    ChangeButton(2);
}

