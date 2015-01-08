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

int ANTHILL::act(unsigned int currTick, int mode)
{
		bool item, item1;
		ITEM* temp, *temp1;
		int status = 0;

		item = this->ownArea->hasFood();
		item1 = this->ownArea->hasWater();

		if(item && item1)		//Create new Ant when Food is on Anthill Area
		{
			temp = this->ownArea->getFood();
			temp1 = this->ownArea->getWater();

			temp->hasTombstone = true;
			temp1->hasTombstone = true;

			this->ownArea->placeAnt(NULL);

			//this->changedList = true; abgelöst
			status = 1;

		}

		if(mode == 1) cout << "Ameisenhügel" << endl;
		this->age++;
		return status;
}
