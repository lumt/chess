#ifndef BISHOP_H
#define BISHOP_H

#include "ChessBoard.h"
#include "ChessPieces.h"


class Bishop : public Piece {
public:
	Bishop(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);

	~Bishop() {}
};


#endif