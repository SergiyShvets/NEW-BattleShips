#ifndef PLAYER_H_
#define PLAYER_H_

#include "Navy.h"
#include "NavyFactory.h"
#include "UsNavyFactory.h"
#include "ChinaNavyFactory.h"

#include "Board.h"

class Player {
public:
	Player();
	virtual ~Player();
	Navy *CreateNavy(NavyFactory *navyFactory, POSITION pos, Coord *coord);
	bool PlaceNavy(Board<int> *board, Navy *navy);

private:
	void GeneratePosition(Ship* ship);
};

#endif /* PLAYER_H_ */
