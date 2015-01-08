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
#include <typeinfo>
#include "../header/FACTORY.h"

using namespace std;

class ITEM; //forward declaration
class FACTORY; //Forward declaration

class AREA
{
	public:

		list<ITEM *> itemsOnArea;
		AREA *north;	//Neighbour Field Up
		AREA *south;	//Neighbour Field Down
		AREA *west;		//Neighbour Field Left
		AREA *east;		//Neighbour Field Right
		FACTORY* factory;
		bool isNest;

		ITEM* placeAnt(ITEM* transferItem);
		ITEM* placeAnthill(ITEM* transferItem);
		ITEM* placeFood(ITEM* transferItem);
		ITEM* placeWater(ITEM* transferItem);

		bool hasFood();
		bool hasWater();
		ITEM* getFood();
		ITEM* getWater();
		void deleteTombstones();

		unsigned int getAntNum();
		unsigned int getFoodNum();
		unsigned int getWaterNum();

		void moveNorth(ITEM* item);
		void moveSouth(ITEM* item);
		void moveWest(ITEM* item);
		void moveEast(ITEM* item);


	AREA();
	~AREA();
};



#endif /* SRC_AREA_H_ */
