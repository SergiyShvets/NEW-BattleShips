#ifndef NAVYFACTORY_H_
#define NAVYFACTORY_H_

#include "logger.h"

#include "Ship.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Cruiser.h"
#include "Carrier.h"

/**
 *The base abstract Navy Factory class
 *using Abstract Factory Pattern to create ships
 */

class NavyFactory {
public:
	NavyFactory();
	virtual ~NavyFactory();

	/**
	 *Virtual methods to create new ships
	 */
	virtual Ship* CreateSubmarine(POSITION &pos, Coord *coord) = 0;
	virtual Ship* CreateDestroyer(POSITION &pos, Coord *coord) = 0;
	virtual Ship* CreateCruiser(POSITION &pos, Coord *coord) = 0;
	virtual Ship* CreateCarrier(POSITION &pos, Coord *coord) = 0;

protected:

	/** The name of current factory*/
	std::string _factoryName;
};

#endif /* NAVYFACTORY_H_ */
