/*
The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once.
starting position is a[0][0] 
*/

#include<iostream>
using namespace std;

bool isValidPosition(int posX, int posY, int visitedSquares[8][8]) {

  return (posX>=0 && posX < 8  && posY >=0 && posY <8  && visitedSquares[posX][posY] == -1);
}


bool startTheVisit(int posX, int posY, int visitedSquares[8][8], int  moveCounter, int *possibleMovesX, int *possibleMovesY ) {

  if( moveCounter == 64 ) return true;
  
  //try all the next moves
  for( int i=0; i<8; i++)  {
    int posX_next = posX + possibleMovesX[i];
    int posY_next = posY + possibleMovesY[i];
    if( !isValidPosition(posX_next, posY_next, visitedSquares ) ) {
	 continue;
    }
    else {
      visitedSquares[posX_next][posY_next] = moveCounter ;
      if( startTheVisit(posX_next, posY_next, visitedSquares, moveCounter+1, possibleMovesX, possibleMovesY) == true ) {
	return true; 
      }
      else 
	visitedSquares[posX_next][posY_next] = -1;
    }
   }
  return false;
}

int main() {
 
  int possibleMovesX[] = {-2, -1, 1, 2, 2, 1, -1, -2 };
  int possibleMovesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

  int visitedSquares[8][8];
  for( int i=0; i<8; i++ )
    for( int j=0; j<8; j++ )
      visitedSquares[i][j]=-1;
  visitedSquares[0][0] = 0; //starting point 
  
  startTheVisit(0, 0, visitedSquares, 1, possibleMovesX, possibleMovesY); 
   
  for( int i=0; i<8; i++ ) {
    for( int j=0; j<8; j++ ) {
      cout<<visitedSquares[i][j]<<" ";
    }
   cout<<"\n"; 
  }

}
