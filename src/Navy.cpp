#include "Navy.h"

Navy::Navy(NavyFactory *navyFactory) {

}

Navy::~Navy() {

	for(auto navySize : navyShips) {
		delete navySize;
	}

}

