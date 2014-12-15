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

ITEM* FACTORY::createAnt()
{

	return new ANT;
}
ITEM* FACTORY::createAnthill()
{

	return new ANTHILL;
}
ITEM* FACTORY::createFood()
{

	return new FOOD;
}
ITEM* FACTORY::createWater()
{
	return new WATER;
}




