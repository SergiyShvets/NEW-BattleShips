#include "logger.h"
#include "Board.h"
#include "Ship.h"
#include "Submarine.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Player.h"
#include "Navy.h"
#include "NavyFactory.h"
#include "UsNavyFactory.h"
#include "ChinaNavyFactory.h"

#include <cstdlib>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <ctime>

#define AAP_NAME "BattleShips"

int main() {

	Logger::Open(AAP_NAME ".log", DBG, 1000000);
	LOG(INFO, "main(): Application Start" << '\n');

	POSITION pos = HORIZONTAL;
	Coord *coord = new Coord();



	Player *player = new Player();

	Board<int> *board = new Board<int>();
	board->SetBoardName("My Board");

	NavyFactory *usNavyFactory = new UsNavyFactory();
	Navy *usNavy = player->CreateNavy(usNavyFactory, pos, coord);

	player->PlaceNavy(board, usNavy);


	board->PrintBoard();
	std::cout << std::endl;

	coord->x = 0;

	for (int x = 0; x < 10; x++){
		coord->y = 0;
		for(int y = 0; y < 10; y++) {

			std::cout << "x:" << coord->x << " y:" << coord->y << std::endl;
			board->HitBoard(coord);

			board->PrintBoard();

			for(auto x : usNavy->GetNavyShips())
				board->Foo(x);

			if(!board->AllShipsDestroyed()) {
				std::cout << "Game Over" << std::endl;
				return 0;
			}

			++coord->y;
			sleep(1);
		}
		++coord->x;
	}
	LOG(INFO, "main(): Application Over");
	Logger::Close();

	return 0;
}
