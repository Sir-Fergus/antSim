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

void ANTHILL::act(unsigned int currTick)
{

	cout << "Ameisen Hügel" << endl;
}
