/*
 * ant.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#include "../header/ANT.h"

ANT::ANT()
{
	this->hasTombstone = false;
	this->ownArea = NULL;
	this->maxAge = 9;  //Default MaxAge
	this->age = 0;
	this->changedList = false;
}

ANT::~ANT()
{


}

void ANT::act(unsigned int currTick, int mode)
{
	if(this->maxAge == currTick) this->hasTombstone = true;



	if(mode == 1) cout << "Ameise" << endl;
}


