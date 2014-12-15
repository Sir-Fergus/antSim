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
	if(transferItem == NULL)
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
	if(transferItem == NULL)
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
	if(transferItem == NULL)
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
	if(transferItem == NULL)
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
