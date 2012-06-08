/*
 * SneeuwMan.cpp
 *
 *  Created on: 28 feb. 2012
 *      Author: Wiebe
 */

#include "SneeuwMan.hpp"

SneeuwMan::SneeuwMan(int positionX, int positionY,int popBreedte,int popHoogte) // constructor
{
	this->positionX		=positionX;
	this->positionY		=positionY;

	this->popHoogte		=popHoogte;
	this->popBreedte	=popBreedte;
}

void SneeuwMan::move(int direction,int upDirection)				// verplaats de sneeuwman
{
		this->positionX = positionX+direction;
		this->positionY = positionY-upDirection;
}

void SneeuwMan::draw()
{
	maSetColor( 0xffffff );														// Zet de kleur wit
	maDrawText( 90, 20, "Sneeuwman" );											// Zet text boven aan

	maFillRect( positionX-5, positionY,popBreedte+10,popHoogte); 		 		// Teken het lichaam van de sneeuwpop

	maFillRect( positionX, positionY-popHoogte,popBreedte,popHoogte); 			// Teken het hoofd van de sneeuwpop

	maSetColor( 0x000000 );														// zet de kleur op zwart

	maFillRect( positionX+10, positionY-30,10,10);								// Teken de ogen van de sneeuwpop Links
	maFillRect( positionX+35, positionY-30,10,10);								// Teken de ogen van de sneeuwpop Rechts
	maFillRect( positionX+8, positionY-10,40,4);								// Teken de mond van de sneeuwpop


	maUpdateScreen();															// refresh scherm zodat er getekend wordt
}
;
