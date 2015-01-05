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
	newOne->age = this->env->tickCnt;
	newOne->maxAge = this->env->tickCnt + this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createAnthill()
{
	ITEM* newOne;

	newOne = new ANTHILL;
	newOne->age = this->env->tickCnt;
	newOne->maxAge = 1000; //this->env->tickCnt + this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createFood()
{
	ITEM* newOne;

	newOne = new FOOD;
	newOne->age = this->env->tickCnt;
	newOne->maxAge = this->env->tickCnt + this->defaultMaxAgeGlobal;

	return newOne;
}
ITEM* FACTORY::createWater()
{
	ITEM* newOne;

	newOne = new WATER;
	newOne->age = this->env->tickCnt;
	newOne->maxAge = this->env->tickCnt + this->defaultMaxAgeGlobal;

	return newOne;
}

void FACTORY::setDefaultMaxAgeGlobal(unsigned int maxAge)
{
	this->defaultMaxAgeGlobal = maxAge;
	this->env = ENVIRONMENT::createInstance(1,1);
}



