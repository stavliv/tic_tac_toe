#include <iostream>
#include "player.h"
#include "board.h"

using namespace std;

Player::Player(char myId, char opId){
  this->myId = myId;
  this->opId = opId;
}

int Player::getOpId(){
  return opId;
}

char Player::getMyId(){
  return myId;
}

int humanPlayer::play(Board *nodeBoard){
  int move;
  cout << endl << "enter the position you wanna play:" << endl;
  cin >> move ;
  
  return move;
}


int computerPlayer::minimax(Board* nodeBoard, int depth, bool isMax, int alpha, int beta){
  //evaluation
  if(nodeBoard->checkWinner(myId)){
    return 10 - depth;
  }
  else if(nodeBoard->checkWinner(opId)){
    return -10 + depth;
  }
  else if(nodeBoard->isDraw()){
    return 0;
  }
  //maximizer is playing
  //int best;
  if(isMax){
    
    int best = -100;
    for(int i = 0; i < 9; i++){
      if(nodeBoard->board[i] == ' '){
        
       // Board* childBoard = new Board(nodeBoard, i, myId );
        //childBoard->printBoard();
        nodeBoard->board[i] = myId;

         best = minimax(nodeBoard, depth + 1, !isMax, alpha, beta ) > best? minimax(nodeBoard, depth + 1, !isMax, alpha, beta ) : best;

         alpha = best > alpha? best : alpha;

         if(beta <= alpha){
           break;
         }
         
        //best = minimax(childBoard, depth + 1, !isMax ) > best? minimax(childBoard, depth + 1, !isMax ) : best;
        nodeBoard->board[i] = ' ';
        //delete childBoard;
      }
    }
    return best;
  }
  //minimizer is playing
  else{
    int best = 100;
    for(int i = 0; i < 9; i++){
      if(nodeBoard->board[i] == ' '){
        
       // Board* childBoard = new Board(nodeBoard, i, opId );
        nodeBoard->board[i] = opId;

        best = minimax(nodeBoard, depth + 1, !isMax, alpha, beta ) < best? minimax(nodeBoard, depth + 1, !isMax, alpha, beta ) : best;

        beta = best < beta? beta : best;

        if(beta <= alpha){
          break;
        }
        //best = minimax(childBoard, depth + 1, isMax ) < best? minimax(childBoard, depth + 1, isMax ) : best;
        nodeBoard->board[i] = ' ';
        //delete childBoard;
      }
    }
    return best;
  }
  //return best;
}

int computerPlayer::findBestMove(Board* nodeBoard){
  int bestVal = -100;
  int bestMove = -1;

  int moveVal;
  for(int i = 0; i < 9; i++){
    if(nodeBoard->board[i] == ' '){
        //Board* childBoard = new Board(nodeBoard, i, opId );
        nodeBoard->board[i] = myId;
        //int moveVal = minimax(childBoard, 0, false);
         moveVal = minimax(nodeBoard, 0, false, -100, 100);
        //cout << moveVal<<endl;
        nodeBoard->board[i] = ' ';
        //delete childBoard;

        if(moveVal > bestVal){
          bestVal = moveVal;
          bestMove = i;
        }
    }
  }
  //cout<<"!!!!!!!!!!!!" << bestMove<<endl;;
  return bestMove;
  
  
}

int computerPlayer::play(Board *nodeBoard){
  bool empty = true;
  for(int i = 0; i < 9; i++){
    if(nodeBoard->board[i] != ' '){
      empty = false;
      break;
    }
  }
  //return empty == true? 4 : findBestMove(nodeBoard);
  return  findBestMove(nodeBoard);
}