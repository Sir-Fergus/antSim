/*
 * FACTORY.cpp
 *
 *  Created on: 18.11.2014
 *      Author: Gerold
 */

#include "../header/FACTORY.h"



FACTORY::FACTORY() {

	this->defaultMaxAgeGlobal = 0;

}

FACTORY::~FACTORY() {
	// TODO Auto-generated destructor stub
}

FACTORY* FACTORY::create_instance()
{
	static FACTORY factoryInstance;

	return &factoryInstance;

}

ITEM* FACTORY::createAnt()
{
	ITEM* newOne;

	newOne = new ANT;
	newOne->maxAge = this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createAnthill()
{
	ITEM* newOne;

	newOne = new ANTHILL;
	newOne->maxAge = this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createFood()
{
	ITEM* newOne;

	newOne = new FOOD;
	newOne->maxAge = this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createWater()
{
	ITEM* newOne;

	newOne = new WATER;
	newOne->maxAge = this->defaultMaxAgeGlobal;

	return newOne;
}

void FACTORY::setDefaultMaxAgeGlobal(unsigned int maxAge)
{
	this->defaultMaxAgeGlobal = maxAge;
}



