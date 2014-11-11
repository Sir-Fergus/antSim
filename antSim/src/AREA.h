/*
 * area.h
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#ifndef SRC_AREA_H_
#define SRC_AREA_H_


#include <iostream>
#include <list>
#include "ITEM.h"

using namespace std;

class AREA
{
	public:

		list<ITEM *> itemsOnArea;
		AREA *north;	//Neighbour Field Up
		AREA *south;	//Neighbour Field Down
		AREA *west;		//Neighbour Field Left
		AREA *east;		//Neighbour Field Right


	AREA();
	~AREA();
};



#endif /* SRC_AREA_H_ */
