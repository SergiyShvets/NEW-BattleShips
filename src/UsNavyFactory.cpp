#include "UsNavyFactory.h"

UsNavyFactory::UsNavyFactory() {

	_factoryName = "United States Factory";

	LOG(INFO, "USNavyFactory::USNavyFactory() "
			<< "Created factory: "
			<< _factoryName << "\n");

}

UsNavyFactory::~UsNavyFactory() {

	LOG(INFO, "UsNavyFactory::~USNavyFactory() "
			<< "Destroyed factory: "
			<< _factoryName << "\n");

}

