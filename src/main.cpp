#include <iostream>
#include <thread>

#include "logger.h"

#include "Navy.h"
#include "NavyFactory.h"
#include "UsNavyFactory.h"
#include "ChinaNavyFactory.h"

#define AAP_NAME "BattleShips"

int main() {

	Logger::Open(AAP_NAME ".log", DBG, 1000000);
	LOG(INFO, "main(): Application Start" << '\n');



	LOG(INFO, "main(): Application Over");
	Logger::Close();

	return 0;
}
