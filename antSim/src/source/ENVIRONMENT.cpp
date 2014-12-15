/*
 * environment.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#include "../header/ENVIRONMENT.h"

ENVIRONMENT::ENVIRONMENT()
{

	this->startArea= new AREA;
	this->envExists= 0;
	this->sizeX = 0;
	this->sizeY = 0;
	this->tickCnt = 0;

}

ENVIRONMENT::~ENVIRONMENT()
{
	delete this->startArea;

}

int ENVIRONMENT::createEnvironment(unsigned int sizeX, unsigned int sizeY)
{
	int status=0;
	unsigned int i, j;

	AREA *lastArea=this->startArea;
	AREA *newArea=NULL;

	for(i=0; i<sizeX; i++)
	{

		for(j=0; j<sizeY; j++)
		{
			if(i==0 && j==0) continue;  //Bei ersten element nichts zu tun --

			newArea= new AREA;

			if(i == 0)
			{
				newArea->north = lastArea;
				lastArea->south= newArea;
			}else if(j == 0)
			{
				lastArea = this->startArea;
				while(lastArea->east != NULL) lastArea = lastArea->east;

				newArea->west = lastArea;
				lastArea->east = newArea;
			}
			else
			{
				newArea->north = lastArea;
				lastArea->south= newArea;
				newArea->west = lastArea->west->south;
				lastArea->west->south->east = newArea;
			}

			lastArea = newArea;
		}

	}
	return status;
}

void ENVIRONMENT::printEnvironment()
{
	AREA *currArea;
	AREA *currArea1;

	currArea=this->startArea;
	currArea1 = currArea;


	while(currArea->east != NULL)
	{

		currArea1 = currArea;

		while(currArea1->south != NULL)
		{
			cout<<"X ";
			currArea1 = currArea1->south;
		}

	cout<<"X"<<endl;
	currArea = currArea->east;
	}


	currArea1 = currArea;

	while(currArea1->south != NULL)
	{
		cout<<"X ";
		currArea1 = currArea1->south;
	}

	cout<<"X"<<endl;



	/*Eventuell Einen Printmodus für die Ausgabe der Listen auf den Areas machen
	 *
	 * currArea = env->startArea;

	for(i=0; i<env->sizeX; i++)
	{
		for(k=0; k<i; k++) //In neue spalte springen
		{
			currArea = currArea->east;
		}

		for(j=0; j<env->sizeY; j++) //Spalte durchlaufen
		{
			list = currArea->itemsOnArea;
			for(std::list<ITEM *>::iterator list_iter = list.begin(); list_iter != list.end(); list_iter++)
						{

							(*list_iter)->act();

						}
			currArea = currArea->south;
		}
		currArea = env->startArea;

	}*/

}




ENVIRONMENT* ENVIRONMENT::createInstance(unsigned int sizeX, unsigned int sizeY)
{
	static ENVIRONMENT instance;
	if(instance.envExists == 0)
	{
		instance.createEnvironment(sizeX,sizeY);
		instance.envExists = 1;
		instance.sizeX = sizeX;
		instance.sizeY = sizeY;
	}

	return &instance;
}

void ENVIRONMENT::placeInital(unsigned int ant, unsigned int food, unsigned int water)
{
	unsigned int i, j, k, i1, randNum, cntAnt, cntFood, cntWater;
	AREA* currArea;

	currArea = this->startArea;
	cntAnt = ant;
	cntFood = food;
	cntWater = water;

	srand(time(0));


		for(i=0; i<this->sizeX; i++)
		{
			for(k=0; k<i; k++) //In neue spalte springen
			{
				currArea = currArea->east;
			}

			for(j=0; j<this->sizeY; j++) //Spalte durchlaufen
			{
				if(i == sizeX/2 && j == sizeY/2)	//place Anthill und Ants in the middle
				{
					currArea->placeAnthill(NULL);
					for(; cntAnt>0; cntAnt--)
					{
						currArea->placeAnt(NULL);
					}
					for(i1=0; i1<5; i1++)
					{
						currArea->placeFood(NULL);
						currArea->placeWater(NULL);
					}
				}

				//for(i1=0;i1<r1;i1++) //Anzahl des Items welche auf File kommen Wie wird die vorgegebene zahl auf das feld zufällig aufgeteilt?

//				if(cntAnt != 0)		//place Ants on Area
//				{
//					randNum = rand()%3;
//					for(i1=0; i1<randNum; i1++)
//					{
//						if(cntAnt != 0)
//						{
//							currArea->placeAnt();
//							cntAnt--;
//						}
//					}
//				}

				if(cntFood != 0)		//place Food on Area
				{
					randNum = rand()%3;
					for(i1=0; i1<randNum; i1++)
					{
						if(cntFood != 0)
						{
							currArea->placeFood(NULL);
							cntFood--;
						}
					}
				}

				if(cntWater != 0)		//place Water on Area
				{
					randNum = rand()%3;
					for(i1=0; i1<randNum; i1++)
					{
						if(cntWater != 0)
						{
							currArea->placeWater(NULL);
							cntWater--;
						}
					}
				}

				currArea = currArea->south;
			}
			currArea = startArea;

		}

		cout<<"Rest Ant: "<<cntAnt<<"\nRest Food: "<<cntFood<<"\nRest Water: "<<cntWater<<endl;

}

void ENVIRONMENT::actAll(int mode)
{
	unsigned int i, k, j;
	AREA* currArea;
	list<ITEM *> list;
	bool listEdited = false;

	currArea = this->startArea;

	for(i=0; i<this->sizeX; i++)
	{
		for(k=0; k<i; k++) //In neue spalte springen
		{
			currArea = currArea->east;
		}

		for(j=0; j<this->sizeY; j++) //Spalte durchlaufen
		{
			list = currArea->itemsOnArea;

			if(mode == 1) cout<<"----- AREA x: "<<i<<" y: "<<j<<" -----"<<endl;

			do //Iteration der Area Item List neu starten wenn etwas gelöscht wurde -> sonst besteht gefahr der Speicherzugriffsverletzung durch den Iterator
			{
				listEdited = false;

				for(std::list<ITEM *>::iterator list_iter = list.begin(); list_iter != list.end(); list_iter++) //Durch Area Item List iterrieren und acten
				{
					if((*list_iter)->hasTombstone)
					{
						list.erase(list_iter);
						listEdited = true;
						break;
					}
					else if((*list_iter)->age <= this->tickCnt)
					{
						(*list_iter)->act(this->tickCnt);
						(*list_iter)->age++;

						if((*list_iter)->changedList)	//Wenn Act die ITEM List verändert hat Iteration neu starten.
						{
							listEdited = true;
							break;
						}
					}
				}

			}while(listEdited);

			currArea = currArea->south;
		}
		currArea = this->startArea;
	}
	this->tickCnt++;

}


