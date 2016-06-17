#ifndef BOARD_H_
#define BOARD_H_

#include "Ship.h"

#include <string>
#include <vector>
#include <iostream>

template<typename CellState>
class Board {
public:

	/**
	 * C-tor initialize board with size 10x10 and empty cells
	 */
	Board();

	/**
	 * D-tor of the board
	 */
	virtual ~Board();

	/**
	 * Method to place ship on the board
	 * @param ship - ship which will be placed
	 */
	bool PlaceShip(Ship *ship);

	/**
	 * Check if all ships was destroyed
	 * @return true - if all ships was destroyed, false if the are any valid ships
	 */
	bool DestroyedShips();

	/**
	 * Prints the Board
	 */
	void PrintBoard();
	/**
	 * Clear all the board, set status of cells empty
	 */
	void ClearBoard();

	/**
	 * @param boardName - set the Board name
	 */
	std::string SetBoardName(std::string boardName);

private:

	/** The name of the board */
	std::string _boardName;

	/** Board of any type*/
	std::vector<std::vector<CellState*> > _board;

	/** Pointers cell state status*/
	CellState *empty;
	CellState *deck;
	CellState *hitDeck;
	CellState *miss;
	CellState *stealth;
	/** The size of board columns and rows*/
	const int BOARD_SIZE;

	/**
	 * Methods to check ships coordinates and ship collision
	 * @param coordX - x row coordinate
	 * @param coordY - y column coordinate
	 * @param MAX_COORD - maximum permissible value of the coordinate
	 * @param MIN_COORD - minimum permissible value of the coordinate
	 * @param shipPos - position of a ship in the board
	 * @param SHIP_DECKS - size of the ship
	 * @return - true if all it's ok
	 */
	bool CheckShipCoord(volatile int coordX, volatile int coordY, const int MAX_COORD,
			const int MIN_COORD, volatile POSITION shipPos,
			const int SHIP_DECKS);
	bool CheckShipCollision(volatile int coordX, volatile int coordY, const int MIN_COORD,
			const int MAX_COORD, volatile POSITION shipPos,
			const int SHIP_DECKS);
};


template<typename CellState>
Board<CellState>::Board() :
BOARD_SIZE(10) {

	empty = new CellState();
	deck = new CellState();
	hitDeck = new CellState();
	miss = new CellState();
	stealth = new CellState();

	_boardName = "Board";

	_board.resize(BOARD_SIZE);
	for (auto &rows : _board) {
		rows.resize(BOARD_SIZE);
		for (auto &cols : rows) {
			cols = empty;
		}
	}
}

template<typename CellState>
Board<CellState>::~Board() {

	delete empty;
	delete deck;
	delete hitDeck;
	delete miss;
	delete stealth;
}

template<typename CellState>
void Board<CellState>::PrintBoard() {

	char cell;
	char emptyCell = ' ';
	char deckCell = 'S';
	char hitDeckCell = 'X';
	char missCell = '.';
	char errorCell = 'E';
	std::string col = "#|A|B|C|D|E|F|G|H|I|J|#";
	std::string line = "=======================";

	std::cout << line << std::endl;
	std::cout << "      " << _boardName << std::endl;
	std::cout << line << std::endl;
	std::cout << col;

	std::cout << std::endl;

	for (auto &rows : _board) {

		static int row = 0;
		std::cout << row << '|';

		for (auto &cols : rows) {

			if (cols == empty)
				cell = emptyCell;
			else if (cols == deck)
				cell = deckCell;
			else if (cols == hitDeck)
				cell = hitDeckCell;
			else if (cols == miss)
				cell = missCell;
			else if (cols == stealth)
				cell = emptyCell;
			else
				cell = errorCell;

			std::cout << cell << '|';
		}
		std::cout << row << std::endl;
		++row;
	}
	std::cout << col << std::endl;
	std::cout << line << std::endl;
}

template<typename CellState>
void Board<CellState>::ClearBoard() {

	for (auto &rows : _board) {
		for (auto &cols : rows) {
			cols = empty;
		}
	}
}

template<typename CellState>
std::string Board<CellState>::SetBoardName(std::string boardName) {

	return _boardName = boardName;
}

template<typename CellState>
bool Board<CellState>::CheckShipCoord(volatile int coordX, volatile int coordY, const int MAX_COORD,
		const int MIN_COORD, volatile POSITION shipPos,
		const int SHIP_DECKS) {

	if (coordX > MAX_COORD || coordY > MAX_COORD)
		return false;
	else if (coordX < MIN_COORD || coordY < MIN_COORD)
		return false;

	switch (shipPos) {
	case VERTICAL:
		if (coordX + SHIP_DECKS < MIN_COORD)
			return false;
		else if (coordX + SHIP_DECKS > MAX_COORD)
			return false;

		break;
	case HORIZONTAL:
		if (coordY + SHIP_DECKS < MIN_COORD)
			return false;
		else if (coordY + SHIP_DECKS > MAX_COORD)
			return false;

		break;
	default:
		return true;
	}
	return true;
}

template<typename CellState>
bool Board<CellState>::CheckShipCollision(volatile int coordX, volatile int coordY,
		const int MIN_COORD, const int MAX_COORD, volatile POSITION shipPos,
		const int SHIP_DECKS) {

	const int BOARD_CELL = 1;

	for (int x = coordX - BOARD_CELL; x <= coordX + BOARD_CELL; x++) {
		for (int y = coordY - BOARD_CELL; y <= coordY + BOARD_CELL; y++) {
			if (x < MIN_COORD || x > MAX_COORD || y < MIN_COORD
					|| y > MAX_COORD)
				continue;

			switch (shipPos) {
			case VERTICAL:
				if (_board[x][y] == deck) {
					return false;
				}
				if (_board[coordX + SHIP_DECKS][coordY] == deck) {
					return false;
				}
				for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++) {
					if (_board[coordX + shipSize][coordY] != empty) {
						return false;
					}
				}
				break;
			case HORIZONTAL:
				if (_board[x][y] == deck) {
					return false;
				}
				if (_board[x][coordY + SHIP_DECKS] == deck) {
					return false;
				}
				for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++) {
					if (_board[x][coordY + shipSize] != empty) {
						return false;
					}
				}
				break;
			default:
				return true;
				break;
			}
		}
	}

	return true;
}

template<typename CellState>
bool Board<CellState>::PlaceShip(Ship* ship) {

	const int MAX_COORD = 10;
	const int MIN_COORD = 0;
	const int SHIP_DECKS = ship->GetShipDecks();
	volatile int coordX = ship->GetShipCoord()->x;
	volatile int coordY = ship->GetShipCoord()->y;
	volatile POSITION shipPos = ship->GetShipPos();
	std::string name = ship->GetShipName();

	if(!CheckShipCoord(coordX,coordY, MAX_COORD, MIN_COORD, shipPos, SHIP_DECKS))
		return false;

	if(!CheckShipCollision(coordX, coordY, MIN_COORD, MAX_COORD, shipPos, SHIP_DECKS))
		return false;

	if (shipPos == VERTICAL) {
		for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++)
			_board[coordX + shipSize][coordY] = deck;
	} else if (shipPos == HORIZONTAL) {
		for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++)
			_board[coordX][coordY + shipSize] = deck;
	}

	return true;
}
#endif /* BOARD_H_ */
