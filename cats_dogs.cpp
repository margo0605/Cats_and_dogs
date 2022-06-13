#include "cats_dogs.h"
#include "ui_cats_dogs.h"
#include <QTabBar>
#include <needhelp.h>
#include <QStyleOption>
#include <QDebug>
#include <QFontDatabase>

Cats_Dogs::Cats_Dogs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cats_Dogs)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setMaximumHeight(500);
    ui->tabWidget->setCurrentIndex(1);
    Interface();
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


void Cats_Dogs::on_pushButton_2_clicked()
{
    ChangeButton(1);
}


void Cats_Dogs::on_pushButton_clicked()
{
    ChangeButton(2);
}
