#ifndef CRUISER_H_
#define CRUISER_H_

#include "Ship.h"

class Cruiser : public Ship {
public:
	Cruiser(POSITION &pos, Coord *coord);
	virtual ~Cruiser();

	void ShipInfo();
};

#endif /* CRUISER_H_ */
