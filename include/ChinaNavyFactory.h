#ifndef CHINANAVYFACTORY_H_
#define CHINANAVYFACTORY_H_

#include "NavyFactory.h"

class ChinaNavyFactory : public NavyFactory {
public:
	ChinaNavyFactory();
	virtual ~ChinaNavyFactory();

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

#endif /* CHINANAVYFACTORY_H_ */
