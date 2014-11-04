/*
 * environment.h
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#ifndef SRC_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_H_

#include <iostream>
#include <string>

#include "area.h"

using namespace std;

class ENVIRONMENT
{
	public:

	AREA *startArea;

	void printEnvironment();
	static ENVIRONMENT* createInstance(unsigned int sizeX, unsigned int sizeY);
	~ENVIRONMENT();

	private:

	int envExists;

	ENVIRONMENT();
	int createEnvironment(unsigned int sizeX, unsigned int sizeY);
};



#endif /* SRC_ENVIRONMENT_H_ */
