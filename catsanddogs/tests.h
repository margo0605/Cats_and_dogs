//
// Created by Маргарита Ведмедева on 25.06.2022.
//

#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QtTest/QtTest>
#include <time.h>
#include <QTimer>
#include <QFontDatabase>
#include <fstream>

/*!
 * \brief Тестирование
 * \version 1.0
 * ТДД - позволяет не откладывать на потом написание юнит тестов, добиваться хорошего покрытия и, что важнее всего, контролировать изменения, вносимые в систему. Любая неожиданная ветка поведения приведет к падению тестов.
 */

class AppTest : public QObject {
    Q_OBJECT

private:
    bool myCondition() {
        return true;
    }

private

    slots :
    void initTestCase() {
        qDebug("Проверка работоспособности игры...");
    }

    void basicComparison() {
        QVERIFY(true);
        QCOMPARE(1, 1);
    }

    void basicComparison2() {
        QVERIFY(myCondition());
        QVERIFY(1 != 2);
    }

    void timer() {
        timer = new QTimer(this);
        QVERIFY(timer != null);
    }

    void checking_fonts() {
        int id = QFontDatabase::addApplicationFont(":/fonts/After Cheret Bold.ttf");
        QVERIFY(id != 0);

        int i = QFontDatabase::addApplicationFont(":/fonts/Dynasty.ttf");
        QVERIFY(id != 0);
    }

    void map_generator() {
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                GameField[r][c] = '-';
            }
        }

        bool flag = false;

        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (GameField[r][c]) != '-' {
                    flag = true
                }
            }
        }

        char Field[5][5] = {
                {'-','-','-','-','-'},
                {'-','-','-','-','-'},
                {'-','-','-','-','-'},
                {'-','-','-','-','-'},
                {'-','-','-','-','-'},
        };
        QVERIFY(Field == GameField);
        QVERIFY(flag != true);
    }

    void filesChecker() {
        std::ofstream out;

        out.open("fonts/After Cheret Bold.ttf");
        out.close();
        QVERIFY(out != null);

        out.open("fonts/Dynasty.ttf");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-3.png");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-6.png");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-9.png");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-11.png");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-12.png");
        out.close();
        QVERIFY(out != null);

        out.open("pic/pngwing.com-13.png");
        out.close();
        QVERIFY(out != null);

    }

    void playerLock() {
        player = 'C'
        if (player == 'D') {
            PlayerLocked = false;
        } else {
            PlayerLocked = true;
        }
        QVERIFY(PlayerLocked != true);
    }

    void cleanupTestCase() {
        qDebug("Отключение.");
    }
};

#endif //CATSDOGS_TESTS_H
