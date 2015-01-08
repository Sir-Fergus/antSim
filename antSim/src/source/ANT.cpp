/*
 * ant.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#include "../header/ANT.h"

ANT::ANT()
{
	this->hasTombstone = false;
	this->ownArea = NULL;
	this->maxAge = 9;  //Default MaxAge
	this->age = 0;
	this->changedList = false;
	this->relHopsNorth = 0;
	this->relHopsSouth = 0;
	this->relHopsWest = 0;
	this->relHopsEast = 0;
	this->lastAreaDirection = 0;
	this->dirHelp = false;
	this->payload = NULL;
}

ANT::~ANT()
{


}

int ANT::act(unsigned int currTick, int mode)
{
	int status = 0, direction=0, envEdge = -1, envEdge1 = -1; //-1 weil kein definierter zustand damit wird es nicht in betracht gezogen wenn man sich nicht am rand befindet
	ITEM* p;
	if(this->maxAge == currTick) this->hasTombstone = true;

	//srand(time(0)); wurde bei place initial initialisiert

	if(this->payload == NULL)
	{
		if(this->ownArea->hasFood() && !(this->ownArea->isNest))
		{
			this->payload = this->ownArea->getFood();
			status = 1;
		}
		else if(this->ownArea->hasFood() && !(this->ownArea->isNest))
		{
			this->payload = this->ownArea->getWater();
			status = 1;
		}
		else	//move
		{
			if(this->ownArea->north == NULL) envEdge = 0;
			else if(this->ownArea->south == NULL) envEdge = 1;
			if(this->ownArea->west == NULL) envEdge1 = 2;
			else if(this->ownArea->east == NULL) envEdge1 = 3;

			do	//find direction, berücksichtigen das nicht in die Richtung aus der wir gekommen sind zurückgegangen wird und kein segfault am rand des feldes erzeugt wird
			{
				direction = rand()%4;

			}while(direction == this->lastAreaDirection || direction == envEdge || direction == envEdge1);

			if(direction == 0) //Move North
			{
				this->lastAreaDirection = 1; // Last Direction on new Area is South
				this->ownArea->moveNorth(this);
				this->relHopsSouth--;
				this->relHopsNorth++;
				status = 1;

			}else if(direction == 1) //Move South
			{
				this->lastAreaDirection = 0; // Last Direction on new Area is North
				this->ownArea->moveSouth(this);
				this->relHopsNorth--;
				this->relHopsSouth++;
				status = 1;
			}
			else if(direction == 2) //Move West
			{
				this->lastAreaDirection = 3; // Last Direction on new Area is East
				this->ownArea->moveWest(this);
				this->relHopsEast--;
				this->relHopsWest++;
				status = 1;
			}else if(direction == 3) //Move East
			{
				this->lastAreaDirection = 2; // Last Direction on new Area is West
				this->ownArea->moveEast(this);
				this->relHopsWest--;
				this->relHopsEast++;
				status = 1;
			}

		}
	}else	//There is Payload
	{
		if(this->ownArea->isNest)
		{
			p = this->payload;
			this->ownArea->placeFood(p);
			this->payload = NULL;

		}else
		{
			if((this->relHopsNorth > 0) && this->dirHelp) //Go south back home
			{
				this->ownArea->moveSouth(this);
				this->relHopsNorth--;
				this->relHopsSouth++;

			}else if((this->relHopsSouth > 0) && this->dirHelp) //Go north back home
			{
				this->ownArea->moveNorth(this);
				this->relHopsSouth--;
				this->relHopsNorth++;

			}else if((this->relHopsWest > 0) && !(this->dirHelp)) //Go east back home
			{
				this->ownArea->moveEast(this);
				this->relHopsWest--;
				this->relHopsEast++;

			}else if((this->relHopsEast > 0) && !(this->dirHelp)) //Go west back home
			{
				this->ownArea->moveWest(this);
				this->relHopsEast--;
				this->relHopsWest++;

			}
			this->dirHelp = !this->dirHelp;
		}
		status = 1;
	}


	if(mode == 1) cout << "Ameise" << endl;
	this->age++;

	return status;
}


