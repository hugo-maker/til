#include <iostream>
using namespace std;

int main()
{
  enum square
  {
    Empty = 0,
    Pawn,
    Rook,
    Knight,
    Bishop,
    King,
    Queen
  };

  square chess_board[8][8];

  chess_board[0][0] = chess_board[0][7] = Rook;
  chess_board[7][0] = chess_board[7][7] = Rook;

  chess_board[0][1] = chess_board[0][6] = Knight;
  chess_board[7][1] = chess_board[7][6] = Knight;

  chess_board[0][2] = chess_board[0][5] = Bishop;
  chess_board[7][2] = chess_board[7][5] = Bishop;

  chess_board[0][3] = Queen;
  chess_board[7][3] = Queen;

  chess_board[0][4] = King;
  chess_board[7][4] = King;

  chess_board[1][0] = chess_board[1][1] = chess_board[1][2] = chess_board[1][3] = chess_board[1][4] = chess_board[1][5] = chess_board[1][6] = chess_board[1][7] = Pawn; 
  chess_board[6][0] = chess_board[6][1] = chess_board[6][2] = chess_board[6][3] = chess_board[6][4] = chess_board[6][5] = chess_board[6][6] = chess_board[6][7] = Pawn;

  chess_board[2][0] = chess_board[2][1] = chess_board[2][2] = chess_board[2][3] = chess_board[2][4] = chess_board[2][5] = chess_board[2][6] = chess_board[2][7] = Empty; 
  chess_board[3][0] = chess_board[3][1] = chess_board[3][2] = chess_board[3][3] = chess_board[3][4] = chess_board[3][5] = chess_board[3][6] = chess_board[3][7] = Empty; 
  chess_board[4][0] = chess_board[4][1] = chess_board[4][2] = chess_board[4][3] = chess_board[4][4] = chess_board[4][5] = chess_board[4][6] = chess_board[4][7] = Empty;
  chess_board[5][0] = chess_board[5][1] = chess_board[5][2] = chess_board[5][3] = chess_board[5][4] = chess_board[5][5] = chess_board[5][6] = chess_board[5][7] = Empty;
}
