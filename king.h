#ifndef KING_H
#define KING_H

#include "ChessBoard.h"
#include "ChessPieces.h"

class King : public Piece {
public:
	King(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);

	~King() {} 
};

#endif