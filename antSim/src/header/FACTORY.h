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
#include "../header/ENVIRONMENT.h"

using namespace std ;

class ITEM; //forward declaration
class ENVIRONMENT; //forward declaration


class FACTORY {
public:

	ENVIRONMENT* env;

	static FACTORY* create_instance();

	ITEM* createAnt();
	ITEM* createAnthill();
	ITEM* createFood();
	ITEM* createWater();

	void setDefaultMaxAgeGlobal(unsigned int maxAge);


	~FACTORY();

private:

	unsigned int defaultMaxAgeGlobal;
	FACTORY();

};

#endif /* FACTORY_H_ */
