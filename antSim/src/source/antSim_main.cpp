/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>

#include "../header/ENVIRONMENT.h"
#include "../header/FACTORY.h"
#include "../header/ITEM.h"
#include "../header/ANT.h"
#include "../header/ANTHILL.h"
#include "../header/FOOD.h"
#include "../header/WATER.h"

int main()
{
	int i;
	ENVIRONMENT* env;
	list<ITEM *> list;
	env = ENVIRONMENT::createInstance(5,5);

	for(i=0;i<=3;i++)
	{
		env->startArea->itemsOnArea.push_front(new ANT);
		env->startArea->itemsOnArea.push_front(new ANTHILL);
		env->startArea->itemsOnArea.push_front(new FOOD);
		env->startArea->itemsOnArea.push_front(new WATER);
	}


	list = env->startArea->itemsOnArea;

	for(std::list<ITEM *>::iterator list_iter = list.begin();
	    list_iter != list.end(); list_iter++)
	{

		(*list_iter)->act();

	}



	env->printEnvironment();
	return 0;
}

