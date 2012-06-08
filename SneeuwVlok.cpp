/*
 * SneeuwVlok.cpp
 *
 *  Created on: 28 feb. 2012
 *      Author: Wiebe
 */


#include "SneeuwVlok.hpp"


SneeuwVlok::SneeuwVlok(int positionX, int positionY,int size) // constructor
{
		this->positionX		= positionX;
		this->positionY		= positionY;
		this->size			= size;
		this->dead			= false;
}

void SneeuwVlok::draw() // teken een vlok
{


	maSetColor( 0xffffff );														// Zet de kleur wit
	maFillRect( positionX, positionY,size,size);

}

void SneeuwVlok::fall(int groundLevel)
{
	this->positionY = this->positionY +1;
	if (positionY >= groundLevel)						// als sneeuwvlok de grond raakt stopt hij met vallen
	{
		this->dead = true;
	}

}

bool SneeuwVlok::isDead()
	{
		return this->dead;

	}




