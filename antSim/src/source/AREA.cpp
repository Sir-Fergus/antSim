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
	this->itemsOnArea.push_front(this->factory->createAnt());
}

void AREA::placeAnthill()
{
	this->itemsOnArea.push_front(this->factory->createAnthill());
}

void AREA::placeFood()
{
	this->itemsOnArea.push_front(this->factory->createFood());
}

void AREA::placeWater()
{
	this->itemsOnArea.push_front(this->factory->createWater());
}
