/*
 * ANTHILL.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_ANTHILL_H_
#define SRC_ANTHILL_H_

#include <iostream>
#include <stdlib.h>
#include "../header/ITEM.h"

using namespace std;

class FOOD; //Forward decleration


class ANTHILL : public ITEM
{
public:

	void act(unsigned int currTick);

	ANTHILL();
	~ANTHILL();
};


#endif /* SRC_ANTHILL_H_ */
