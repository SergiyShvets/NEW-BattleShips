#include "Player.h"

#include <ctime>
#include <cstdlib>

Player::Player() {

	srand(static_cast<unsigned int>(time(NULL)));

}

Player::~Player() {

}

void Player::GeneratePosition(Ship* ship) {

	int x = rand()%10;
	int y = rand()%10;
	POSITION pos = static_cast<POSITION>(rand()% 2);
	ship->SetShipCoord(x, y);
	ship->SetShipPos(pos);

}

bool Player::PlaceNavy(Board<int> *board, Navy *navy){



	//	bool placed = false;
	//
	//	for(auto ship : navy->GetNavyShips()) {
	//		while(placed == false) {
	//			GeneratePosition(ship);
	//			if(board->PlaceShip(ship)) {
	//				std::cout << "OK" << std::endl;
	//				break;
	//			} else {
	//				placed = false;
	//			}
	//		}
	//	}

	for(auto ship : navy->GetNavyShips()) {

		GeneratePosition(ship);
		board->PlaceShip(ship);
	}
	return true;
}

Navy *Player::CreateNavy(NavyFactory *navyFactory, POSITION pos, Coord *coord){

	Navy *navy = new Navy();

	std::vector<Ship*> navyShips;

	navyShips.push_back(navyFactory->CreateSubmarine(pos, coord));
	navyShips.push_back(navyFactory->CreateDestroyer(pos, coord));
	navyShips.push_back(navyFactory->CreateCruiser(pos, coord));
	navyShips.push_back(navyFactory->CreateCarrier(pos, coord));

	navy->SetNavyShips(navyShips);

	return navy;
}
