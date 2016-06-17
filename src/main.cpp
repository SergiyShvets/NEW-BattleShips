#include <iostream>
#include <thread>

#include "logger.h"
#include "Board.h"
#include "Ship.h"
#include "Submarine.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"

#include <cstdlib>

#define AAP_NAME "BattleShips"

//void foo (Board<int> *board, Ship *ship) {
//
//	int x = rand()%10;
//	int y = rand()%10;
//	POSITION pos = static_cast<POSITION>(rand()% 2);
//	ship->SetShipCoord(x, y);
//	ship->SetShipPos(pos);
//
//	board->PlaceShip(ship);
//
//}

int main() {

	Logger::Open(AAP_NAME ".log", DBG, 1000000);
	LOG(INFO, "main(): Application Start" << '\n');

//	POSITION pos = HORIZONTAL;
//	Coord *coord = new Coord();
//
//	Ship *car = new Carrier(pos, coord);
//	Ship *sub = new Submarine(pos, coord);
//	Ship *cru = new Cruiser(pos, coord);
//	Ship *des = new Destroyer(pos, coord);
//
//	std::vector<Ship*> ships;
//
//	ships.push_back(car);
//	ships.push_back(sub);
//	ships.push_back(car);
//	ships.push_back(cru);
//	ships.push_back(des);
//
//
//	Board<int> *board = new Board<int>();
//	board->SetBoardName("MyBoard");
//
//	for(auto x : ships) {
//		foo(board, x);
//		x->ShipInfo();
//	}
//
//
//	board->PrintBoard();
//	std::cout << std::endl;
//
//	Board<std::string> *board1 = new Board<std::string>();
//	board1->SetBoardName("ENEMyBoard");
//	board1->PlaceShip(ships[1]);
//	board1->PrintBoard();

	LOG(INFO, "main(): Application Over");
	Logger::Close();

	return 0;
}
