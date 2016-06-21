#include "Destroyer.h"

Destroyer::Destroyer(POSITION pos, Coord *coord) :
Ship(pos, coord) {

	_shipName = "Destroyer";
	_decks = DESTROYER;
	_pos = pos;
	_coord = coord;
	_wasDestroyed = false;

	LOG(INFO,
			"Destroyer::Destroyer(POSITION &pos, Coord *coord) : Ship(pos, coord) "
			<< " Created ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');

}

Destroyer::~Destroyer() {

	LOG(INFO,
			"Destroyer::~Destroyer()"
			<< " Destroyed ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');
}

void Destroyer::ShipInfo() {

	std::cout << "Ship: " << _shipName << '\n'
			<< "Decks: " << _decks << '\n'
			<< "Position: " << _pos << '\n'
			<< "Coordinates x:" << _coord->x
			<< " y:" << _coord->y << '\n'
			<< "Status:" << _wasDestroyed << '\n'
			<< std::endl;

}

int Destroyer::DestroyedShip(int decks) {

	_decks = decks;
	--_decks;
	return _decks;
}
