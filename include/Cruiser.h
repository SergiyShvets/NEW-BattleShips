#ifndef CRUISER_H_
#define CRUISER_H_

#include "Ship.h"

class Cruiser : public Ship {
public:

	Cruiser(POSITION pos, Coord *coord);
	virtual ~Cruiser();

	int DestroyedShip(int decks);
	void ShipInfo();
};

#endif /* CRUISER_H_ */
