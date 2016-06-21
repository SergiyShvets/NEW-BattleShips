#ifndef DESTROYER_H_
#define DESTROYER_H_

#include "Ship.h"

class Destroyer : public Ship {
public:

	Destroyer(POSITION pos, Coord *coord);
	virtual ~Destroyer();

	int DestroyedShip(int decks);
	void ShipInfo();
};

#endif /* DESTROYER_H_ */
