/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>
#include "environment.h"


int main()
{
	ENVIRONMENT* env = ENVIRONMENT::createInstance(5,5);


	env->printEnvironment();
	return 0;
}

