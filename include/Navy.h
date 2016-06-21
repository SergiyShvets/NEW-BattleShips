#ifndef NAVY_H_
#define NAVY_H_

#include "NavyFactory.h"
#include "Ship.h"

#include <vector>

/**
 *This class is used to create navy using NavyFactory class
 */
class Navy {
public:
	/**
	 *@param *navyFactory - choose which factory will be used to create navy
	 */
	//Navy(NavyFactory *navyFactory, POSITION pos, Coord *coord);
	/**
	 * D-tor - delete all ships from navyShips container
	 */
	virtual ~Navy();

	const std::vector<Ship*>& GetNavyShips() const {
		return _navyShips;
	}

	void SetNavyShips(std::vector<Ship*>& navyShips) {
		_navyShips = navyShips;
	}

public:
	/** This vector will be contain navy ships */
	std::vector<Ship*> _navyShips;
};

#endif /* NAVY_H_ */
