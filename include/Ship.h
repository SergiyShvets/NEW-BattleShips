#ifndef SHIP_H_
#define SHIP_H_

#include "logger.h"

#include <string>
#include <iostream>

/**
 *The structure of coordinates (x and y)
 *on which will be placed ships
 */
typedef struct Coord {

	/** As a default coords are initialized by 0; */
	Coord() :
		x(0), y(0) {
	};

	/** Vertical coordinate */
	volatile int x;
	/** Horizontal coordinate */
	volatile int y;

} Coord;

/**
 *The enum of ship position on a board (vertical or horizontal)
 */
typedef enum {
	VERTICAL, HORIZONTAL
}  POSITION;

/**
 *The enum of ship types:
 *Submarine have 1 deck,
 *Destroyer - 2 decks,
 *Cruiser - 3 decks,
 *Carrier - 4 decks
 */
typedef enum {
	SUBMARINE = 1, DESTROYER, CRUISER, CARRIER
} SHIP_TYPE;

/**
 * This is the base abstract ship class
 */
class Ship {
public:

	/**
	 * @param *pos - position of current ship
	 * @param *coord - coordinates of current ship
	 */
	Ship(POSITION pos, Coord *coord);

	/**
	 * Virtual d-tor of the base abstract class
	 */
	virtual ~Ship();

	/**
	 * Virtual get methods of the base Ship class
	 */
	virtual std::string GetShipName() const {
		return _shipName;
	}
	virtual POSITION GetShipPos() const {
		return _pos;
	}
	virtual Coord *GetShipCoord() const {
		return _coord;
	}
	virtual int GetShipDecks() const {
		return _decks;
	}
	virtual bool GetShipDestroyed() const {
		return _wasDestroyed;
	}

	/**
	 * Virtual set coordinate method of base Ship class
	 * @param x - coordinate x
	 * @param y - coordinate y
	 */
	virtual void SetShipCoord(int x, int y);

	/**
	 * Virtual set position method of base Ship class
	 * @param pos - position of the ship, vertical or horizontal
	 */
	virtual void SetShipPos(POSITION pos);


	/**
	 * This method shows information about current ship
	 */
	virtual void ShipInfo() = 0;

	virtual int DestroyedShip(int decks) = 0;

protected:
	/** The name of current ship*/
	std::string _shipName;
	/** The type of ship*/
	int _decks;
	/** The position of current ship*/
	POSITION _pos;
	/** The coordinates of current  ship*/
	Coord *_coord;
	/** The status of current ship*/
	bool _wasDestroyed;

};

#endif /* SHIP_H_ */
