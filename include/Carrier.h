#ifndef CARRIER_H_
#define CARRIER_H_

#include "Ship.h"

class Carrier : public Ship {
public:
	Carrier(POSITION &pos, Coord *coord);
	virtual ~Carrier();

	void ShipInfo();
};

#endif
