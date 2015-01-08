/*
 * FOOD.cpp
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#include "../header/FOOD.h"



FOOD::FOOD()
{
	this->hasTombstone = false;
	this->ownArea = NULL;
	this->age = 0;
	this->changedList = false;
}

FOOD::~FOOD() {
	// TODO Auto-generated destructor stub
}

int FOOD::act(unsigned int currTick, int mode)
{
	if(mode == 1) cout << "Food" << endl;
	this->age++;

	return 0;
}


