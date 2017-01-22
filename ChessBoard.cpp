#include <iostream>
#include "ChessBoard.h"

/* CHESSBOARD */
// Constructor
ChessBoard::ChessBoard() {
	// Resets board
	resetBoard();
}

// Function to check if move submitted is legal
bool ChessBoard::legalMove(const string from, const string to) {

	// if values given is garbage
	if (from.size() > 2 || to.size() > 2) {
		cout << "Garbage value, input something proper" << endl;
		return false;
	}

	// Check Out of bounds of 'from'
	if (from[0] < 'A' || from[0] > 'H' ||
		from[1] < '1' || from[1] > '8') {
		cout << "Can't move a piece from outside the board!" << endl;
		return false;
	}

	// Check OOB of 'to'
	if (to[0] < 'A' || to[0] > 'H' ||
		to[1] < '1' || to[1] > '8') {
		cout << "Can't move a piece out of the board!" << endl;
		return false;
	}

	// check if there is piece at location
	if (board[from] == NULL) {
		cout << "There is no piece at position " << from << "!" << endl;
		return false;
	}

	// check who's turn it is 
	if (board[from]->player != turn) {
		cout << "It is not " << (turn == WHITE? "Black's " : "White's ");
		cout << "turn to move!" << endl;
		return false;
	}

	// Check if piece is able to move to position 
	// either by occupied by own pieces or that the piece can't jump
	if (!board[from]->movePiece(board, from, to)) {
		cout << *board[from] << " cannot move to " << to << "!" << endl;
		return false;
	}

	// sees if move would put your own King in Check by
	if(selfCheck(from, to, turn)) {
		cout << *board[from] << " attempts to move from " << from << " to ";
		cout << to << endl;
		cout << "Illegal move, "<< (turn == WHITE? "White's " : "Black's ");
		cout << "King is in check." << endl << endl;	
		return false;
	}

	return true;
}

// Function to move the piece if possible
void ChessBoard::submitMove(const string from, const string to) {

	if (ended) {
		cout << "The game has ended." << endl;
		return;
	}

	// Check from and to if legal
	if (legalMove(from, to)) {

		// Print movement
		cout << *board[from] << " moves from " << from;
		cout << " to " << to;

		// Taking piece: delete and print out
		if (board[to]) {
			map<string, Piece*>::iterator dead_piece;
			dead_piece = board.find(to);
			cout << " taking " << *board[to];
			delete dead_piece->second;
		}
		cout << endl;

		// update the board
		board[to] = board[from];
		board[from] = NULL;

		// if opponent is in check, tell user
		if (inCheck(!turn)) {
			// check for checkmate
			if (endMatch(!turn)) {
				// set end game something so you can't submit anymore moves
				cout << (turn == WHITE? "Black" : "White") << " is in ";
				cout << "checkmate" << endl;
				ended = true;
				return;
			}
			cout << (turn == WHITE? "Black" : "White") << " is in check";
			cout << endl;
		}

		// check if opponent is in stalement
		if (endMatch(!turn)) {
			cout << (turn == WHITE? "Black" : "White") << " is in ";
			cout << "stalemate" << endl;
			ended = true;
			return;
		}

		// Change turn
		turn = (turn == WHITE? BLACK : WHITE);
	}
}

// Function to try out the move and see if you have placed yourself in check
bool ChessBoard::selfCheck(const string from, const string to,
							const bool thisturn)
{
	// store eaten piece
	Piece* temp_eaten = NULL;

	// check if you have eaten a piece
	if(board[to] != NULL) {
		temp_eaten = board[to];
	}
	
	// try to move the piece in the submitted move
	Piece* temp_from = board[from];	// temp pointer to previous position
	board[to] = board[from];		// change point to piece moving in
	board[from] = NULL;				// previous is now NULL

	// Check if yourself is in check after your move
	if (inCheck(thisturn)) {

		// if eaten something, point the thing back
		if (temp_eaten)
			board[to] = temp_eaten;
		else
			board[to] = NULL;

		board[from] = temp_from;

		return true;
	} 

	// revert everything back
	if (temp_eaten)
		board[to] = temp_eaten;
	else
		board[to] = NULL;

	board[from] = temp_from;

	return false;
}

// Function to return all available moves for current player
list<string> ChessBoard::getAllMoves(const bool currentplayer) {

	list<string> piece;
	list<string> all_moves;

	for(map<string, Piece*>::iterator it = board.begin();
		it != board.end(); it++)
	{
		if(it->second != NULL && it->second->player == currentplayer)
		{
			piece.clear();
			piece = it->second->availableMoves(board, it->first);
			all_moves.insert(all_moves.end(), piece.begin(), piece.end());	
		}
	}

	return all_moves;
}

// Function to check if you have been checkmated
bool ChessBoard::endMatch(const bool currentplayer) {

	// iterate over all pieces on the board that is yours
	// try to move that piece then selfCheck()
	list<string> piece_moves;

	// iterate over all pieces on the board
	for(map<string, Piece*>::iterator piece = board.begin();
		piece != board.end(); piece++)
	{
		// if that piece is yours
		if(piece->second != NULL && piece->second->player == currentplayer)
		{
			// get moves for that piece
			piece_moves.clear();
			piece_moves = piece->second->availableMoves(board, piece->first);

			// iterate over all moves
			for (list<string>::iterator move = piece_moves.begin();
				move != piece_moves.end(); move++)
			{
				// If you can place yourself out of check (not check)
				if(!selfCheck(piece->first, *move, !turn)) {
					return false;
				}
			}
		}
	}

	return true;
}


// Function to check if you are being checked
bool ChessBoard::inCheck(const bool currentplayer) {

	// gets list of all attacking move of current opponent
	list<string> attacks = getAllMoves(!currentplayer);

	// if your king is in it, return true because it is in check
	for(list<string>::iterator it = attacks.begin();
		it != attacks.end(); it++)
	{
		// iterate over your own pieces and sees if it is a King
		if(board[*it] != NULL && board[*it]->player == currentplayer &&
			board[*it]->name == "King") {
			return true;
		}
	}

	// otherwise not in check
	return false;
}

// Function to reset the board to starting position
void ChessBoard::resetBoard() {

	// deletes all values from the board (calling destructor)
	for (map<string, Piece*>::iterator it = board.begin();
		it != board.end(); it++)
	{
		delete it->second;
	}

	// clear all keys
	board.clear();

	// Initialize board to NULL
	string s;
	for (char file = 'A'; file <= 'H'; file++) {
		for (char rank = '1'; rank <= '8'; rank++) {
			s = string() + file + rank;
			board[s] = NULL;
		}
	}

	// STANDARD STARTING POSITION
	// Kings
	board["E1"] = new King(WHITE);
	board["E8"] = new King(BLACK);

	// Queens
	board["D1"] = new Queen(WHITE);
	board["D8"] = new Queen(BLACK);

	// Bishops
	board["C1"] = new Bishop(WHITE);
	board["F1"] = new Bishop(WHITE);
	board["C8"] = new Bishop(BLACK);
	board["F8"] = new Bishop(BLACK);

	// Knights
	board["B1"] = new Knight(WHITE);
	board["G1"] = new Knight(WHITE);
	board["B8"] = new Knight(BLACK);
	board["G8"] = new Knight(BLACK);

	// Rooks
	board["A1"] = new Rook(WHITE);
	board["H1"] = new Rook(WHITE);
	board["A8"] = new Rook(BLACK);
	board["H8"] = new Rook(BLACK);

	// Pawns
	board["A2"] = new Pawn(WHITE);
	board["B2"] = new Pawn(WHITE);
	board["C2"] = new Pawn(WHITE);
	board["D2"] = new Pawn(WHITE);
	board["E2"] = new Pawn(WHITE);
	board["F2"] = new Pawn(WHITE);
	board["G2"] = new Pawn(WHITE);
	board["H2"] = new Pawn(WHITE);

	board["A7"] = new Pawn(BLACK);
	board["B7"] = new Pawn(BLACK);
	board["C7"] = new Pawn(BLACK);
	board["D7"] = new Pawn(BLACK);
	board["E7"] = new Pawn(BLACK);
	board["F7"] = new Pawn(BLACK);
	board["G7"] = new Pawn(BLACK);
	board["H7"] = new Pawn(BLACK);

	// SETS STARTING TURN TO WHITE
	turn = WHITE;
	ended = false;

	cout << "A new chess game is started!" << endl;
}
/* END CHESSBOARD */
