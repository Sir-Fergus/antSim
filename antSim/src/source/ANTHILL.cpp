/*
 * ANTHILL.cpp
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#include "../header/ANTHILL.h"

ANTHILL::ANTHILL() {

	this->hasTombstone = false;
	this->ownArea = NULL;
	this->age = 0;
	this->changedList = false;
}

ANTHILL::~ANTHILL() {
	// TODO Auto-generated destructor stub
}

void ANTHILL::act(unsigned int currTick, int mode)
{
		bool item, item1;

		item = this->ownArea->hasFood();
		item1 = this->ownArea->hasWater();

		if(item && item1)		//Create new Ant when Food is on Anthill Area
		{
			delete(this->ownArea->getFood());
			delete(this->ownArea->getWater());

			this->ownArea->placeAnt(NULL);

			this->changedList = true;

		}

		if(mode == 1) cout << "Ameisenhügel" << endl;
}
