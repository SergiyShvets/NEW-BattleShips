#include "Carrier.h"

Carrier::Carrier(POSITION pos, Coord *coord) :
		Ship(pos, coord) {

	_shipName = "Aircraft Carrier";
	_decks = CARRIER;
	_pos = pos;
	_coord = coord;
	_wasDestroyed = false;

	LOG(INFO,
			"Carrier::Carrier(POSITION &pos, Coord *coord) : Ship(pos, coord)"
					<< " Created ship: " << _shipName
					<< " Decks: " << _decks
					<< " Position: " << _pos
					<< " Coordinates x:" << _coord->x
					<< " y:" << _coord->y
					<< " Status:" << _wasDestroyed << '\n');
}

Carrier::Carrier() {

	_shipName = "Aircraft Carrier";
		_decks = CARRIER;
		_pos = HORIZONTAL;
		_coord = nullptr;
		_wasDestroyed = false;

}
Carrier::~Carrier() {

	LOG(INFO,
			"Carrier::~Carrier()"
					<< " Destroyed ship: " << _shipName
					<< " Decks: " << _decks
					<< " Position: " << _pos
					<< " Coordinates x:" << _coord->x
					<< " y:" << _coord->y
					<< " Status:" << _wasDestroyed << '\n');


}

void Carrier::ShipInfo() {

	std::cout << "Ship: " << _shipName << '\n'
			  << "Decks: " << _decks << '\n'
			  << "Position: " << _pos << '\n'
			  << "Coordinates x:" << _coord->x
			  << " y:" << _coord->y << '\n'
			  << "Status:" << _wasDestroyed << '\n'
			  << std::endl;

}
