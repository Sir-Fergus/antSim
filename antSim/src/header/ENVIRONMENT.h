/*
 * environment.h
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#ifndef SRC_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>


#include "../header/AREA.h"

class ITEM; //Forward decleration

using namespace std;

class ENVIRONMENT
{
	public:

		AREA *startArea;
		unsigned int sizeX;
		unsigned int sizeY;
		unsigned int tickCnt;
		void printEnvironment();
		static ENVIRONMENT* createInstance(unsigned int sizeX, unsigned int sizeY);
		void placeInital(unsigned int ant, unsigned int food, unsigned int water, unsigned int maxPileSize);
		void actAll(int mode);

		~ENVIRONMENT();

	private:

		int envExists;

		ENVIRONMENT();
		int createEnvironment(unsigned int sizeX, unsigned int sizeY);
};



#endif /* SRC_ENVIRONMENT_H_ */
