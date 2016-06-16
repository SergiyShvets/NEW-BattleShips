#ifndef USNAVYFACTORY_H_
#define USNAVYFACTORY_H_

#include "NavyFactory.h"

class UsNavyFactory: public NavyFactory {
public:
	UsNavyFactory();
	virtual ~UsNavyFactory();

	Ship* CreateSubmarine(POSITION &pos, Coord *coord) {
		return new Submarine(pos, coord);
	}
	Ship* CreateDestroyer(POSITION &pos, Coord *coord) {
		return new Destroyer(pos, coord);
	}
	Ship* CreateCruiser(POSITION &pos, Coord *coord) {
		return new Cruiser(pos, coord);
	}
	Ship* CreateCarrier(POSITION &pos, Coord *coord) {
		return new Carrier(pos, coord);
	}
};

#endif /* USNAVYFACTORY_H_ */
