#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player{
  protected:
  char myId;
  char opId;

  public:
  int getOpId();
  char getMyId();
  Player(char myId, char opId);
  virtual int play(Board *nodeBoard) = 0;
  ~Player();
};

class humanPlayer : public Player{
  public:
  humanPlayer(char myId, char opId) : Player(myId, opId){};
  int play(Board *nodeBoard);
  ~humanPlayer();
};

class computerPlayer : public Player{
  public:
  computerPlayer(char myId, char opId) : Player(myId, opId){};
  int play(Board *nodeBoard);
  int findBestMove(Board* nodeBoard);
  int minimax(Board* nodeBoard, int depth, bool isMax, int alpha, int beta);
  ~computerPlayer();
};

#endif