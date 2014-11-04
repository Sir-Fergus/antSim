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

using namespace std;

class ANT
{
	public:

	unsigned int age;
	string	role;
 	list<int> payload;


	ANT();
	~ANT();
};



#endif /* SRC_ANT_H_ */


//Different Classes for each role??
