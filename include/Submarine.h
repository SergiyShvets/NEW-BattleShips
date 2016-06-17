#ifndef SUBMARINE_H_
#define SUBMARINE_H_

#include "Ship.h"

class Submarine : public Ship{
public:
	Submarine();
	Submarine(POSITION pos, Coord *coord);
	~Submarine();

	void ShipInfo();
};

#endif /* SUBMARINE_H_ */
