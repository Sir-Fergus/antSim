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
	int i;
	char a;

	ENVIRONMENT* env;
	env = ENVIRONMENT::createInstance(11,11);

	env->startArea->factory->setDefaultMaxAgeGlobal(50);	//Setze Default Max Age für alle Items die erstellt werden



	env->placeInital(1,1,10,5);
	for(i=0;i<=20;i++)
	{
		env->actAll(0);
		env->printEnvironment();
		//cin >>a;
	}

	return 0;
}

