/*
 * WATER.cpp
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#include <string>

#include "../header/WATER.h"


WATER::WATER() {

	this->hasTombstone = false;
	this->ownArea = NULL;
	this->age = 0;
	this->changedList = false;
}

WATER::~WATER() {
	// TODO Auto-generated destructor stub
}

void WATER::act(unsigned int currTick)
{

	cout << "Water" << endl;
}

