#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include <string>
#include <map>				// to store board
#include <list> 			// to store list of available moves
#include "ChessBoard.h"

using namespace std;

// Abstract class for the chess pieces
class Piece {
public:
	string name;
    bool player;

    Piece(bool p);

    // Function to output to outstream
    friend ostream& operator<<(ostream& o, const Piece& p);

    // virtual function to get available moves for the piece
    virtual list<string> availableMoves(map<string, Piece*> &board,
    									string from) = 0;

    // true if piece is able to move there (ie in one of available moves)
    bool movePiece(map<string, Piece*> &board, string from, string to);

    // virtual destructor
    virtual ~Piece() {}
};

#endif