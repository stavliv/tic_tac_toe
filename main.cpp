#include <iostream>
#include "board.h"
#include "player.h"

using namespace std;

int main() {
  //instructions to the players
  cout << "when your turn arrives enter the number of the position you wanna play, the positions are numbered as followed:" << endl;
  cout<<"     |     |     "<<endl;
  cout<<"0"<<"    | "<<"1"<<"   |  "<<"2"<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"3"<<"    | "<<"4"<<"   |  "<<"5"<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"6"<<"    | "<<"7"<<"   |  "<<"8"<<endl;
  cout<<"     |     |     "<<endl;
  cout << "let the battle begin!"<<endl;

  //actual implementation
  Player** players = new Player*[2];
  players[0] = new humanPlayer('X', 'O');
  players[1] = new computerPlayer('O', 'X');
  Board* board = new Board(' ');

  int counter = 0;

  board->printBoard();

  while(board->stillPlaying()){
    cout << "player"<<1 + counter%2 <<"'s turn" << endl;
    board->insertInto(players[counter%2]->play(board), players[counter%2]->getMyId());
    board->printBoard();
    counter++;
  }

  if(board->checkWinner(players[0]->getMyId())){
    cout << "player 1 won!" << endl;
  }  
  else if(board->checkWinner(players[1]->getMyId())){
    cout << "player 2 won!" << endl;
  }  
  else{
    cout << "It's a draw!" << endl;
  }

  return 0;
}