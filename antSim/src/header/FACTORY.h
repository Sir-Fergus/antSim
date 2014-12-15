/*
 * FACTORY.h
 *
 *  Created on: 18.11.2014
 *      Author: Gerold
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "../header/ANT.h"
#include "../header/ANTHILL.h"
#include "../header/FOOD.h"
#include "../header/WATER.h"
//#include "../header/ITEM.h"

using namespace std ;

class ITEM; //forward declaration

class FACTORY {
public:

	static FACTORY* create_instance();

	ITEM* createAnt();
	ITEM* createAnthill();
	ITEM* createFood();
	ITEM* createWater();




	~FACTORY();

private:

	FACTORY();

};

#endif /* FACTORY_H_ */
