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
#include "../header/AREA.h"

using namespace std;


class ANTHILL : public ITEM
{
public:

	void act(unsigned int currTick, int mode);

	ANTHILL();
	~ANTHILL();
};


#endif /* SRC_ANTHILL_H_ */
