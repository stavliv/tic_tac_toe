#include <iostream>
#include "board.h"

using namespace  std;

Board::Board(char x){
  for(int i = 0; i < 9; i++){
    board[i] = x;
  }
}

Board::Board(Board* nodeBoard, int positionOfChange, char id){
  for(int i = 0; i < 9; i++){
    board[i] = nodeBoard->board[i];
  }
  if(board[positionOfChange] == ' '){
    board[positionOfChange] = id;
  }
  else{
    cout << "INVALID POSITION" << endl;
  }
}

int Board::checkWinner(char id){
  // check horizontally
  for(int i = 0; i < 3; i++){
    if(board[i*3 + 0] == id && board[i*3 + 1] == id && board[i*3 + 2] == id){
      return 1;
    }
  }
  // check vertically
  for(int i = 0; i < 3; i++){
    if(board[i + 0] == id && board[i + 3] == id && board[i + 6] == id){
      return 1;
    }
  }
  //check diagonally
  if(board[0] == id && board[4] == id && board[8] == id){
     return 1;
  }
  if(board[2] == id && board[4] == id && board[6] == id){
     return 1;
  }
  return 0;
}

int Board::isDraw(){
  bool isBoardFull = true;
  for(int i = 0; i < 9; i++){
    if (board[i] == ' '){
      isBoardFull = false;
    }
  }
  return (!checkWinner('X') && !checkWinner('O') && isBoardFull);
}

int Board::stillPlaying(){
  return (!checkWinner('X') && !checkWinner('O') && !isDraw());

}

void Board::insertInto(int position, char id){
  if(board[position] == ' '){
    board[position] = id;
  }
  else {
    cout << "INVALID POSITION"<<endl;
    
  }
}

char Board::checkBoard(int position){
  return board[position];
}

void Board::printBoard(){
   cout<<"     |     |     "<<endl;
  cout<<board[0]<<"    | "<<board[1]<<"   |  "<<board[2]<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<board[3]<<"    | "<<board[4]<<"   |  "<<board[5]<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<board[6]<<"    | "<<board[7]<<"   |  "<<board[8]<<endl;
  cout<<"     |     |     "<<endl;
}
