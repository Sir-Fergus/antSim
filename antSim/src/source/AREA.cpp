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


void AREA::placeAnt()
{
	ITEM* item;
	item = this->factory->createAnt();
	item->ownArea = this;
	this->itemsOnArea.push_front(item);
}

void AREA::placeAnthill()
{
	ITEM* item;
	item = this->factory->createAnthill();
	item->ownArea = this;
	this->itemsOnArea.push_front(item);
}

void AREA::placeFood()
{
	ITEM* item;
	item = this->factory->createFood();
	item->ownArea = this;
	this->itemsOnArea.push_front(item);
}

void AREA::placeWater()
{
	ITEM* item;
		item = this->factory->createWater();
		item->ownArea = this;
		this->itemsOnArea.push_front(item);
}
