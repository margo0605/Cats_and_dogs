//
// Created by Маргарита Ведмедева on 25.06.2022.
//

#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QtTest/QtTest>

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
