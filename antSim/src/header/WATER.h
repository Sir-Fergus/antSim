/*
 * WATER.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_WATER_H_
#define SRC_WATER_H_

#include <iostream>
#include "../header/ITEM.h"

using namespace std;

class WATER : public ITEM
{
public:

	void act();

	WATER();
	virtual ~WATER();
};

#endif /* SRC_WATER_H_ */
