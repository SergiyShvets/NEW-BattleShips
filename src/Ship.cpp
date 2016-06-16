#include "Ship.h"

Ship::Ship(POSITION &pos, Coord *coord) {

	_shipName = "Abstract Ship";
	_decks = 0;
	_pos = &pos;
	_coord = coord;
	_wasDestroyed = false;

	LOG(INFO,
			"Ship::Ship(pos, coord) "
				<< "Created ship: "
				<< _shipName << '\n');

}

Ship::~Ship() {
	LOG(INFO,
			"Ship::~Ship() "
				<< "Destroyed ship: "
				<< _shipName << '\n');
}

