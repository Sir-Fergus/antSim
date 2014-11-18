/*
 * FACTORY.cpp
 *
 *  Created on: 18.11.2014
 *      Author: Gerold
 */

#include "../header/FACTORY.h"



FACTORY::FACTORY() {
	// TODO Auto-generated constructor stub

}

FACTORY::~FACTORY() {
	// TODO Auto-generated destructor stub
}

FACTORY* FACTORY::create_instance()
{
	static FACTORY factoryInstance;

	return &factoryInstance;

}

ANT* FACTORY::createAnt()
{

	return new ANT;
}
ANTHILL* FACTORY::createAnthill()
{

	return new ANTHILL;
}
FOOD* FACTORY::createFood()
{

	return new FOOD;
}
WATER* FACTORY::createWater()
{
	return new WATER;
}




