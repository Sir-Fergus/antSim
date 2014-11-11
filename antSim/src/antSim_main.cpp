/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>

#include "ENVIRONMENT.h"


int main()
{
	ENVIRONMENT* env;

	env = ENVIRONMENT::createInstance(5,5);
	env = ENVIRONMENT::createInstance(8,8);

	env->printEnvironment();
	return 0;
}

