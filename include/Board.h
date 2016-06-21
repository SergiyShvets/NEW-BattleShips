#ifndef BOARD_H_
#define BOARD_H_

#include "Ship.h"

#include <string>
#include <vector>

/**
 * The hit result enumeration
 * HIT_TARGET - player hit the ship deck
 * MISS_TARGET - player missed the ship deck
 * SAME_TARGET - player had already shoot there
 * BAD_COORD - player used too big or too small coordinates
 */
typedef enum {
	HIT_TARGET, MISS_TARGET, SAME_TARGET, BAD_COORD
}HIT_RESULT;

template<typename CellState>
class Board {
public:

	bool Foo(Ship *ship);

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
	 * Method to hit the ships
	 * @param coord - x and y coordinates
	 * @return - result of the hit
	 */
	HIT_RESULT HitBoard(Coord *coord);

	/**
	 * Check if all ships was destroyed
	 * @return true - if all ships was destroyed, false if the are any valid ships
	 */
	bool AllShipsDestroyed();

	/**
	 * Prints the Board
	 */
	void PrintBoard();
	/**
	 * Clear all the board, set status of cells _empty
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
	CellState *_empty;
	CellState *_deck;
	CellState *_hitDeck;
	CellState *_miss;
	CellState *_stealth;

	/** The size of board columns and rows*/
	const int BOARD_SIZE;

private:

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
	/**
	 * Method to check hit coordinates
	 * @param x - row coordinate
	 * @param y - column coordinate
	 * @return false if coordinates are wrong
	 */
	bool CheckHit(volatile int x, volatile int y);


};

#endif /* BOARD_H_ */
