#ifndef BOARD_H
#define BOARD_H

class Board{
  
  

  public:
  char board[9];
  Board(char x);
  Board(Board* nodeBoard, int positionOfChange, char id);
  int checkWinner(char id);
  int isDraw();
  int stillPlaying();
  void insertInto(int position, char id);
  char checkBoard(int position);
  void printBoard();
  ~Board();
};

#endif