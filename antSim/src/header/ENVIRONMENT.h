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
#include <time.h>
#include <stdlib.h>

#include "../header/AREA.h"

using namespace std;

class ENVIRONMENT
{
	public:

		AREA *startArea;
		unsigned int sizeX;
		unsigned int sizeY;

		void printEnvironment();
		static ENVIRONMENT* createInstance(unsigned int sizeX, unsigned int sizeY);
		void placeInital(unsigned int ant, unsigned int food, unsigned int water);
		void actAll();

		~ENVIRONMENT();

	private:

		int envExists;

		ENVIRONMENT();
		int createEnvironment(unsigned int sizeX, unsigned int sizeY);
};



#endif /* SRC_ENVIRONMENT_H_ */
