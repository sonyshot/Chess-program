#pragma once
#ifndef MOVELIST_H
#define MOVELIST_H

#include <unordered_map>
#include "Board.h"

class Movelist :public sf::Drawable {
	friend class Board;

	std::vector<std::array<std::array<int, 2>, 2>> m_movelist;
	std::vector<Piece*> m_captureList;
	std::vector<ChessMoves> m_moveType;
	Board * m_board;
	
	std::string m_printMoves = "Movelist:";
	sf::Font m_font;
	sf::Text m_text;

	std::string squareName(std::array<int, 2> square);

	std::string newSquareNotation(std::array<int, 2> square, ChessMoves specialMove);

	std::string printableString(std::array<std::array<int, 2>, 2> square, Piece * piece, ChessMoves specialMove);

	std::unordered_map<std::string, int> m_boardStateMap;

public:
	//need constructor/destructor
	Movelist(Board * board);

	~Movelist();

	std::string hashBoard();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void addToMovelist(std::array<int, 2> currentPos, std::array<int, 2> newPos);

	void removeFromMovelist();

	std::array<std::array<int, 2>, 2> previousMove();

	std::string hashPiece(Piece * piece);
};
#endif // !MOVELIST_H