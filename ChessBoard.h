#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <map>				// to store board
#include <list> 			// to store list of available moves
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "knight.h"
#include "pawn.h"


using namespace std;

enum {WHITE, BLACK};

// Class for the board
class ChessBoard {
private:	
	map<string, Piece*> board;
	bool turn;
	bool ended;
	
public:
	// Constructor
	ChessBoard();

	// check if move submitted was legal
	bool legalMove(const string from, const string to);

	// function to attempt to make the submitted move
	void submitMove(const string from, const string to);

	// To check if in Checkamte or Stalemate
	bool endMatch(const bool currentplayer);

	// To check if you would put yourself in check
	bool selfCheck(const string from, const string to, const bool thisturn);

	// inCheck to see if currently the player is in check
	bool inCheck(const bool currentplayer);

	// Gets all available moves for the current player
	list<string> getAllMoves(const bool currentplayer);

	// resets the board to standard starting position
	void resetBoard();

	~ChessBoard() {}
};

#endif