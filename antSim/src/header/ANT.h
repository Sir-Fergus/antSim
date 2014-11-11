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

using namespace std;

class ANT : public ITEM
{
	public:

	unsigned int age;
	//string	role;
 	list<ITEM *> payload;

 	void act();

	ANT();
	~ANT();
};



#endif /* SRC_ANT_H_ */


//Different Classes for each role??
