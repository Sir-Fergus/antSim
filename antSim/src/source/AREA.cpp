/*
 * area.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */



#include "../header/AREA.h"


AREA::AREA()
{
	this->north=NULL;
	this->south=NULL;
	this->west=NULL;
	this->east=NULL;
	this->factory= FACTORY::create_instance();


	}

AREA::~AREA()
{

}


ITEM* AREA::placeAnt(ITEM* transferItem)
{
	ITEM* item;
	if(transferItem == NULL)	//Create new Object if argument is NULL
	{
		item = this->factory->createAnt();
	}else
	{
		item = transferItem;
	}
	item->ownArea = this;
	this->itemsOnArea.push_front(item);

	return item;
}

ITEM* AREA::placeAnthill(ITEM* transferItem)
{
	ITEM* item;
	if(transferItem == NULL)	//Create new Object if argument is NULL
		{
			item = this->factory->createAnthill();
		}else
		{
			item = transferItem;
		}
	item->ownArea = this;
	this->itemsOnArea.push_front(item);

	return item;
}

ITEM* AREA::placeFood(ITEM* transferItem)
{
	ITEM* item;
	if(transferItem == NULL)	//Create new Object if argument is NULL
		{
			item = this->factory->createFood();
		}else
		{
			item = transferItem;
		}
	item->ownArea = this;
	this->itemsOnArea.push_front(item);

	return item;
}

ITEM* AREA::placeWater(ITEM* transferItem)
{
	ITEM* item;
	if(transferItem == NULL)	//Create new Object if argument is NULL
		{
			item = this->factory->createWater();
		}else
		{
			item = transferItem;
		}
		item->ownArea = this;
		this->itemsOnArea.push_front(item);

		return item;
}

bool AREA::hasFood()
{

	for(std::list<ITEM *>::iterator list_iter1 = this->itemsOnArea.begin(); list_iter1 != this->itemsOnArea.end(); list_iter1++) //Durch Area Item List iterrieren und acten
	{
		if(typeid(*(*list_iter1)) == typeid(FOOD) && !(*list_iter1)->hasTombstone)
		{
			return true; //Food found
		}

	}

	return false; //no Food found
}

bool AREA::hasWater()
{

	for(std::list<ITEM *>::iterator list_iter1 = this->itemsOnArea.begin(); list_iter1 != this->itemsOnArea.end(); list_iter1++) //Durch Area Item List iterrieren
	{
		if(typeid(*(*list_iter1)) == typeid(WATER) && !(*list_iter1)->hasTombstone)
		{
			return true; //Water found
		}

	}

	return false; //no Water found
}

ITEM* AREA::getFood()
{
	ITEM* item;

	if(this->hasFood())
	{
		for(std::list<ITEM *>::iterator list_iter1 = this->itemsOnArea.begin(); list_iter1 != this->itemsOnArea.end(); list_iter1++) //Durch Area Item List iterrieren
			{
				//item = (*list_iter); //debug
				if(typeid(*(*list_iter1)) == typeid(FOOD)  && !(*list_iter1)->hasTombstone)
				{
					item = (*list_iter1);
					this->itemsOnArea.erase(list_iter1); // Items aus liste nehmen

					return item; //rückgabe des entnommenen Items
				}

			}

	}

	return NULL;
}

ITEM* AREA::getWater()
{
	ITEM* item;

		if(this->hasWater())
		{
			for(std::list<ITEM *>::iterator list_iter1 = this->itemsOnArea.begin(); list_iter1 != this->itemsOnArea.end(); list_iter1++) //Durch Area Item List iterrieren und acten
				{
					//item = (*list_iter); //debug
					if(typeid(*(*list_iter1)) == typeid(WATER)  && !(*list_iter1)->hasTombstone)
					{
						item = (*list_iter1);
						this->itemsOnArea.erase(list_iter1); // Items aus liste nehmen

						return item; //rückgabe des entnommenen Items
					}

				}

		}

	return NULL;
}

void AREA::deleteTombstones()
{
	list<ITEM *> *list;
	std::list<ITEM *>::iterator list_iter1, current;

	ITEM* currItem;

	list = &this->itemsOnArea;

	for(list_iter1 = list->begin(); list_iter1 != list->end();) //Durch Area Item List iterrieren und objekte löschen die tombstone haben
	{
		if((*list_iter1)->hasTombstone)
		{
			currItem = (*list_iter1);
			current = list_iter1;
			list_iter1 = list->erase(current);
			delete(currItem);
			continue;
		}
		else
		{
			list_iter1++;
		}
	}

}
