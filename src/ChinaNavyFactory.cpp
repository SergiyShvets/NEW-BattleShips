#include "ChinaNavyFactory.h"

ChinaNavyFactory::ChinaNavyFactory() {

	_factoryName = "China Navy Factory";

	LOG(INFO, "ChinaNavyFactory::ChinaNavyFactory() "
			<< "Created factory: "
			<< _factoryName << "\n");

}

ChinaNavyFactory::~ChinaNavyFactory() {

	LOG(INFO, "ChinaNavyFactory::~ChinaNavyFactory() "
			<< "Destroyed factory: "
			<< _factoryName << "\n");

}

