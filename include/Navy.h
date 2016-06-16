#ifndef NAVY_H_
#define NAVY_H_

#include "NavyFactory.h"
#include "Ship.h"

#include <vector>

class Navy {
public:
	Navy(NavyFactory *navyFactory);
	virtual ~Navy();
private:
	std::vector<Ship*> navyShips;
};

#endif /* NAVY_H_ */
