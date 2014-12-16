/*
 * ITEM.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_

//#include "../header/AREA.h"
//
//using namespace std;

class AREA; //forward declaration

class ITEM {
public:

	AREA* ownArea;
	bool hasTombstone;
	bool changedList;
	unsigned int age;
	unsigned int maxAge;
	virtual void act(unsigned int currTick) = 0; //pure virtual

	ITEM();
	virtual ~ITEM();
};

#endif /* SRC_ITEM_H_ */
