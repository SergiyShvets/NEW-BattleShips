#include "Cruiser.h"

Cruiser::Cruiser(POSITION pos, Coord *coord) :
Ship(pos, coord) {

	_shipName = "Cruiser";
	_decks = CRUISER;
	_pos = pos;
	_coord = coord;
	_wasDestroyed = false;

	LOG(INFO,
			"Cruiser::Cruiser(POSITION &pos, Coord *coord) : Ship(pos, coord) "
			<< " Created ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');



}

Cruiser::~Cruiser() {

	LOG(INFO,
			"Cruiser::~Cruiser()"
			<< " Destroyed ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');

}

void Cruiser::ShipInfo() {

	std::cout << "Ship: " << _shipName
			<< '\n' << "Decks: " << _decks << '\n'
			<< "Position: " << _pos << '\n'
			<< "Coordinates x:" << _coord->x
			<< " y:" << _coord->y << '\n'
			<< "Status:" << _wasDestroyed << '\n'
			<< std::endl;

}

int Cruiser::DestroyedShip(int decks) {

	_decks = decks;
	--_decks;
	return _decks;

}
