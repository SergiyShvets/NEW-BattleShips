#include "NavyFactory.h"

NavyFactory::NavyFactory() {

	_factoryName = " Abstract Factory";

	LOG(INFO, "NavyFactory::NavyFactory() "
			<< "Created factory: "
			<< _factoryName << "\n");

}

NavyFactory::~NavyFactory() {
	LOG(INFO, "NavyFactory::~NavyFactory() "
			<< "Destroyed factory: "
			<< _factoryName << "\n");


}


