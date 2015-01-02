/*
 * FOOD.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

#include <iostream>
#include "../header/ITEM.h"


using namespace std;


class FOOD : public ITEM
{
public:

	void act(unsigned int currTick, int mode);

	FOOD();
	virtual ~FOOD();
};


#endif /* SRC_FOOD_H_ */
