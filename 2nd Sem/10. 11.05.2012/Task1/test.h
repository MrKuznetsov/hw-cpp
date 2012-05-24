#ifndef TEST_H
#define TEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>

#include "tictactoe.h"

class GameTest : public QObject
{
  Q_OBJECT
public:
  explicit GameTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      game = new TicTacToe();
  }

  void cleanup()
  {
      delete game;
  }

  void testVert()
  {
      game->set(0);
      game->set(5);
      game->set(1);
      game->set(4);
      game->set(2);
      QVERIFY(game->checkWin(0) == 1);
  }

  void testHoriz()
  {
      game->set(0);
      game->set(5);
      game->set(3);
      game->set(4);
      game->set(6);
      QVERIFY(game->checkWin(0));
  }

  void testDiag()
  {
      game->set(0);
      game->set(1);
      game->set(4);
      game->set(5);
      game->set(8);
      QVERIFY(game->checkWin(0));
  }

private:
  TicTacToe *game;

};

#endif // TEST_H
