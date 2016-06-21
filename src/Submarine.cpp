#include "Submarine.h"

Submarine::Submarine(POSITION pos, Coord *coord) :
Ship(pos, coord) {

	_shipName = "Submarine";
	_decks = SUBMARINE;
	_pos = pos;
	_coord = coord;
	_wasDestroyed = false;

	LOG(INFO,
			"Submarine::Submarine(POSITION &pos, Coord *coord) : Ship(pos, coord)"
			<< " Created ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');

}

Submarine::~Submarine() {

	LOG(INFO,
			"Submarine::~Submarine()"
			<< " Destroyed ship: " << _shipName
			<< " Decks: " << _decks
			<< '\n');

}

void Submarine::ShipInfo() {

	std::cout << "Ship: "
			<< _shipName << '\n' << "Decks: "
			<< _decks << '\n'
			<< "Position: " << _pos << '\n'
			<< "Coordinates x:" << _coord->x
			<< " y:" << _coord->y << '\n'
			<< "Status:" << _wasDestroyed << '\n'
			<< std::endl;

}

int Submarine::DestroyedShip(int decks) {

	_decks = decks;
	--_decks;
	return _decks;
}


