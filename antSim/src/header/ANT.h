/*
 * ant.h
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#ifndef SRC_ANT_H_
#define SRC_ANT_H_

#include <iostream>
#include <string>
#include <list>
#include "../header/ITEM.h"
#include "../header/AREA.h"

using namespace std;

class ANT : public ITEM
{
	public:

	//string	role;
 	//list<ITEM *> payload;
 	int relHopsNorth;
 	int relHopsSouth;
 	int relHopsWest;
 	int relHopsEast;
 	int lastAreaDirection; // 0-North 1-South 2-West 3-East
 	bool dirHelp;
 	ITEM* payload;

 	int act(unsigned int currTick, int mode);

	ANT();
	~ANT();
};



#endif /* SRC_ANT_H_ */


//Different Classes for each role??
