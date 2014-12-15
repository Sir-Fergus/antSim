/*
 * ITEM.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_

//#include "../header/AREA.h"

using namespace std;

class AREA; //forward declaration

class ITEM {
public:

	AREA* ownArea;
	virtual void act() = 0; //pure virtual

	ITEM();
	virtual ~ITEM();
};

#endif /* SRC_ITEM_H_ */
