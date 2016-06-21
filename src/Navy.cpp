#include "Navy.h"

//Navy::Navy(NavyFactory *navyFactory, POSITION pos, Coord *coord) {
//
//
//}


Navy::~Navy() {

	//Destroy all ships
	for(auto navySize : _navyShips) {
		delete navySize;
	}

}

