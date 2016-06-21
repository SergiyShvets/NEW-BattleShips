#include "Board.h"

#include <iostream>

const int MIN_COORD = 0;
const int MAX_COORD = 10;

template<typename CellState>
Board<CellState>::Board() :
BOARD_SIZE(10) {

	_empty = new CellState();
	_deck = new CellState();
	_hitDeck = new CellState();
	_miss = new CellState();
	_stealth = new CellState();


	//Default board name
	_boardName = "Board";

	//Create 10 x 10 board with empty cells state
	_board.resize(BOARD_SIZE);
	for (auto &rows : _board) {
		rows.resize(BOARD_SIZE);
		for (auto &cols : rows) {
			cols = _empty;
		}
	}
}

template<typename CellState>
Board<CellState>::~Board() {

	delete _empty;
	delete _deck;
	delete _hitDeck;
	delete _miss;
	delete _stealth;
}

template<typename CellState>
void Board<CellState>::PrintBoard() {

	char cell = '0';
	char emptyCell = ' ';
	char deckCell = 'S';
	char hitDeckCell = 'X';
	char missCell = '.';
	char errorCell = 'E';
	int row = 0;
	std::string col = "#|A|B|C|D|E|F|G|H|I|J|#";
	std::string line = "=======================";

	std::cout << line << std::endl;
	std::cout << "      " << _boardName << std::endl;
	std::cout << line << std::endl;
	std::cout << col;
	std::cout << std::endl;
	for (auto& rows : _board) {

		std::cout << row << '|';
		for (auto& cols : rows) {
			if (cols == _empty)
				cell = emptyCell;
			else if (cols == _deck)
				cell = deckCell;
			else if (cols == _hitDeck)
				cell = hitDeckCell;
			else if (cols == _miss)
				cell = missCell;
			else if (cols == _stealth)
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

	//Set all cells with status empty
	for (auto &rows : _board) {
		for (auto &cols : rows) {
			cols = _empty;
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

	//Return false if current coordinate is bigger than MAX_COORD or smaller than MIN_COORD
	if (coordX > MAX_COORD || coordY > MAX_COORD)
		return false;
	else if (coordX < MIN_COORD || coordY < MIN_COORD)
		return false;

	//Return false if ship decks are outside the board
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

	//Required distance between ships to avoid the collision
	const int SHIP_DISTANCE = 1;

	for (int x = coordX - SHIP_DISTANCE; x <= coordX + SHIP_DISTANCE; x++) {
		for (int y = coordY - SHIP_DISTANCE; y <= coordY + SHIP_DISTANCE; y++) {
			if (x < MIN_COORD || x > MAX_COORD || y < MIN_COORD
					|| y > MAX_COORD)
				//continue;
				return false;

			//Check if ship is not placed on another ship
			switch (shipPos) {
			case VERTICAL:
				if (_board[x][y] == _deck) {
					return false;
				}
				if (_board[coordX + SHIP_DECKS][coordY] == _deck) {
					return false;
				}
				for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++) {
					if (_board[coordX + shipSize][coordY] != _empty) {
						return false;
					}
				}
				break;
			case HORIZONTAL:
				if (_board[x][y] == _deck) {
					return false;
				}
				if (_board[x][coordY + SHIP_DECKS] == _deck) {
					return false;
				}
				for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++) {
					if (_board[x][coordY + shipSize] != _empty) {
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

	const int SHIP_DECKS = ship->GetShipDecks();
	volatile int coordX = ship->GetShipCoord()->x;
	volatile int coordY = ship->GetShipCoord()->y;
	volatile POSITION shipPos = ship->GetShipPos();
	std::string shipName = ship->GetShipName();

	if(!CheckShipCoord(coordX, coordY, MAX_COORD, MIN_COORD, shipPos, SHIP_DECKS))
		return false;

	if(!CheckShipCollision(coordX, coordY, MIN_COORD, MAX_COORD, shipPos, SHIP_DECKS))
		return false;

	//Place the ship depending on position
	if (shipPos == VERTICAL) {
		for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++)
			_board[coordX + shipSize][coordY] = _deck;
	} else if (shipPos == HORIZONTAL) {
		for (int shipSize = 0; shipSize < SHIP_DECKS; shipSize++)
			_board[coordX][coordY + shipSize] = _deck;
	}

	std::cout << shipName << " is placed" <<std::endl;
	return true;
}

template<typename CellState>
bool Board<CellState>::CheckHit(volatile int x, volatile int y) {

	//Return false if coordinates are too bigger or too smaller
	if (x > MAX_COORD || x < MIN_COORD)
		return false;
	else if (y > MAX_COORD || y < MIN_COORD)
		return false;

	return true;
}

template<typename CellState>
HIT_RESULT Board<CellState>::HitBoard(Coord *coord){

	volatile int hitX = coord->x;
	volatile int hitY = coord->y;

	if(!CheckHit(hitX,hitY)) {
		std::cout << "Bad coordinates" << std::endl;
		return BAD_COORD;
	}

	if(_board[hitX][hitY] == _deck) {
		_board[hitX][hitY] = _hitDeck;
		std::cout << "Hit" << std::endl;
		return HIT_TARGET;
	} else if (_board[hitX][hitY] == _empty) {
		_board[hitX][hitY] = _miss;
		std::cout << "Miss" << std::endl;
		return MISS_TARGET;
	} else if (_board[hitX][hitY] == _miss || _board[hitX][hitY] == _hitDeck) {
		std::cout << "You have shoot there already" << std::endl;
		return SAME_TARGET;
	}

	return BAD_COORD;
}

template<typename CellState>
bool Board<CellState>::AllShipsDestroyed(){

	//If there are no any cells with deck - game over
	for (auto &rows : _board) {
		for (auto &cols : rows) {
			if(cols == _deck)
				return true;
		}
	}
	return false;
}

template<typename CellState>
bool Board<CellState>::Foo(Ship *ship){

	const int SHIP_DECKS = ship->GetShipDecks();
	volatile int coordX = ship->GetShipCoord()->x;
	volatile int coordY = ship->GetShipCoord()->y;
	//volatile POSITION shipPos = ship->GetShipPos();
	std::string shipName = ship->GetShipName();

	if(_board[coordX][coordY] == _hitDeck) {
		if(ship->DestroyedShip(SHIP_DECKS) == 0) {
		std::cout << shipName << " destroyed" << std::endl;
		return true;
		}
	}
	return false;
}

//This lines are needed to divide template class into .h and .cpp files
template class Board<int>;
template class Board<std::string>;
