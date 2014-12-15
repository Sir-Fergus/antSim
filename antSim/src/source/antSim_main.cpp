/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>

#include "../header/ENVIRONMENT.h"
#include "../header/FACTORY.h"
#include "../header/AREA.h"
#include "../header/ITEM.h"
//#include "../header/ANT.h"
//#include "../header/ANTHILL.h"
//#include "../header/FOOD.h"
//#include "../header/WATER.h"

int main()
{
	ENVIRONMENT* env;
	env = ENVIRONMENT::createInstance(3,3);

	env->startArea->factory->setDefaultMaxAgeGlobal(9);	//Setze Default Max Age für alle Items die erstellt werden

	int i;

	env->placeInital(10,10,10);
	for(i=0;i<=10;i++)
	{
		env->actAll(1);
	}
	env->printEnvironment();
	return 0;
}

