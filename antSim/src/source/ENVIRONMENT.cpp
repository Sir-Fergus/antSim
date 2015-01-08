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

			if(i == 0)	//Wenn in erster Spalte
			{
				newArea->north = lastArea;
				lastArea->south= newArea;
			}else if(j == 0)	//Wenn in erster Zeile
			{
				lastArea = this->startArea;
				while(lastArea->east != NULL) lastArea = lastArea->east; //lastArea Pointer auf den beginn der nächsten Spalte setzen, dazu wird in der ersten Zeile ganz nach rechts gegangen

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

	unsigned int i, j, k, a, w, f;

	currArea=this->startArea;
	currArea1 = currArea;

	char line[] =" ---------";

	cout<<"Tick Number: "<<this->tickCnt<< endl;

	for(i = 0; i < this->sizeX;i++) //Trennlinie zwischen Zeilen
	{
		cout<<line;
		if(i+1 == this->sizeX) cout<<endl;

	}

	for(j=0; j < this->sizeY; j++)
	{

		currArea1 = currArea;

		cout<<"|";
		for(k=0; k < this->sizeX; k++) //Einträge auf den Areas
		{
			if((a=currArea1->getAntNum()) == 0) cout<<setfill(' ')<<setw(3)<<" ";
			else cout<<setw(2)<<a<<"A";
			if((f=currArea1->getFoodNum()) == 0) cout<<setfill(' ')<<setw(3)<<" ";
			else cout<<setw(2)<<f<<"F";
			if((w=currArea1->getWaterNum()) == 0) cout<<setfill(' ')<<setw(3)<<" ";
			else cout<<setw(2)<<w<<"W";
			cout<<"|";
			currArea1 = currArea1->east;
		}
		cout<<endl;

		for(i = 0; i < this->sizeX;i++) //Trennlinie zwischen Zeilen
		{
			cout<<line;
			if(i+1 == this->sizeX) cout<<endl;

		}
		currArea = currArea->south;
	}


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

void ENVIRONMENT::placeInital(unsigned int ant, unsigned int food, unsigned int water, unsigned int maxPileSize)
{
	unsigned int i, j, k,randNum, xCoord, yCoord;
	AREA* currArea;

	currArea = this->startArea;

	srand(time(0));

	xCoord = this->sizeX /2;
	yCoord = this->sizeY /2;

	for(i=0; i<xCoord; i++)		//X Koordinate anspringen
	{
		currArea = currArea->east;
	}
	for(i=0; i<yCoord; i++)		//Y Koordinate anspringen
	{
		currArea = currArea->south;
	}

	for(i=0; i < ant; i++)	//Ants Auf Anthill setzen
	{
		if(i==0)
		{
			currArea->placeAnthill(NULL);
			for(j=0; j<10; j++)
			{
				currArea->placeFood(NULL);
				currArea->placeWater(NULL);
			}
		}

		currArea->placeAnt(NULL);
	}

	for(j=0; j < food; )	//Food verteilen
	{
		currArea= this->startArea;
		xCoord = rand()%(this->sizeX);
		yCoord = rand()%(this->sizeY);

		for(i=0; i<xCoord; i++)		//X Koordinate anspringen
		{
			currArea = currArea->east;
		}
		for(i=0; i<yCoord; i++)		//Y Koordinate anspringen
		{
			currArea = currArea->south;
		}

		randNum = rand()%maxPileSize +1; 	// +1 damit area nicht umsonst angesprungen wird, würde der fall sein wenn randNum 0 wird und damit kein Food gedropt wird.
		for(k=0; k < randNum; k++)
		{
			currArea->placeFood(NULL);
			j++; //food counter increment -> je nach dem wieviel auf die Area gesetzt wird.

		}
	}

	for(j=0; j < water; )	//Water verteilen
		{
			currArea= this->startArea;
			xCoord = rand()%(this->sizeX);
			yCoord = rand()%(this->sizeY);

			for(i=0; i<xCoord; i++)		//X Koordinate anspringen
			{
				currArea = currArea->east;
			}
			for(i=0; i<yCoord; i++)		//Y Koordinate anspringen
			{
				currArea = currArea->south;
			}

			randNum = rand()%maxPileSize +1; 	// +1 damit area nicht umsonst angesprungen wird, würde der fall sein wenn randNum 0 wird und damit kein Food gedropt wird.
			for(k=0; k < randNum; k++)
			{
				currArea->placeFood(NULL);
				j++; //food counter increment -> je nach dem wieviel auf die Area gesetzt wird.

			}
		}

		//cout<<"Rest Ant: "<<cntAnt<<"\nRest Food: "<<cntFood<<"\nRest Water: "<<cntWater<<endl;

}

void ENVIRONMENT::actAll(int mode)
{
	unsigned int i, k, j;
	int status = 0;
	AREA* currArea;
	//ITEM* currItem; debug
	list<ITEM *> *list;
	bool listEdited = false;
	std::list<ITEM *>::iterator current, list_iter;

	this->tickCnt++;
	currArea = this->startArea;

	for(i=0; i<this->sizeX; i++)
	{
		for(k=0; k<i; k++) //In neue spalte springen
		{
			currArea = currArea->east;
		}

		for(j=0; j<this->sizeY; j++) //Spalte durchlaufen
		{

			if(mode == 1) cout<<"----- AREA x: "<<i<<" y: "<<j<<" -----"<<endl;

			do //Iteration der Area Item List neu starten wenn etwas gelöscht wurde -> sonst besteht gefahr der Speicherzugriffsverletzung durch den Iterator
			{
				listEdited = false;
				list = &currArea->itemsOnArea; //An dieser Stelle muss die Liste noch einmal geholt werden. Ansonsten wird die Liste nicht aktualisiert und es sind kaputte ITEM Pointer vorhandne wegen der Bearbeitung die geschehen ist.

				for(list_iter = list->begin(); list_iter != list->end(); ++list_iter) //Durch Area Item List iterrieren und acten
				{
					//currItem = (*list_iter); //debug

					if((*list_iter)->age < this->tickCnt && !(*list_iter)->hasTombstone)
					{
						status = (*list_iter)->act(this->tickCnt, mode);

						if(status)	//Wenn Act die ITEM List verändert hat Iteration neu starten.
						{
							listEdited = true;
							//(*list_iter)->changedList = false; abgelöst
							break;
						}
					}
				}

			}while(listEdited);

			currArea->deleteTombstones();

			currArea = currArea->south;
		}
		currArea = this->startArea;
	}
}


