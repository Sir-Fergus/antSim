/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>

#include "../header/ENVIRONMENT.h"

int main()
{
	ENVIRONMENT* env;
	env = ENVIRONMENT::createInstance(3,3);

	env->startArea->factory->setDefaultMaxAgeGlobal(8);	//Setze Default Max Age für alle Items die erstellt werden

	int i;

	env->placeInital(1,10,10);
	for(i=0;i<=15;i++)
	{
		env->actAll(1);
	}
	env->printEnvironment();
	return 0;
}

