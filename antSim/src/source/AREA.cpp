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

	for(std::list<ITEM *>::iterator list_iter = this->itemsOnArea.begin(); list_iter != this->itemsOnArea.end(); list_iter++) //Durch Area Item List iterrieren und acten
	{
		if(typeid(*(*list_iter)) == typeid(FOOD))
		{
			return 1; //Food found
		}

	}

	return 0; //no Food found
}

bool AREA::hasWater()
{

	for(std::list<ITEM *>::iterator list_iter = this->itemsOnArea.begin(); list_iter != this->itemsOnArea.end(); list_iter++) //Durch Area Item List iterrieren
	{
		if(typeid(*(*list_iter)) == typeid(WATER))
		{
			return 1; //Water found
		}

	}

	return 0; //no Water found
}

ITEM* AREA::getFood()
{
	ITEM* item;

	if(this->hasFood())
	{
		for(std::list<ITEM *>::iterator list_iter = this->itemsOnArea.begin(); list_iter != this->itemsOnArea.end(); list_iter++) //Durch Area Item List iterrieren
			{
				if(typeid(*(*list_iter)) == typeid(FOOD))
				{
					item = (*list_iter);
					this->itemsOnArea.erase(list_iter);

					return item;
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
			for(std::list<ITEM *>::iterator list_iter = this->itemsOnArea.begin(); list_iter != this->itemsOnArea.end(); list_iter++) //Durch Area Item List iterrieren und acten
				{
					if(typeid(*(*list_iter)) == typeid(WATER))
					{
						item = (*list_iter);
						this->itemsOnArea.erase(list_iter);

						return item;
					}

				}

		}

	return NULL;
}

