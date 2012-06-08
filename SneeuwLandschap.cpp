/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author:Wiebe
 */

#include "SneeuwLandschap.hpp"
#include "SneeuwMan.hpp"
#include <conprint.h>

//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;

//int i;
int size;




SneeuwMan* sneeuwMan;
SneeuwVlok* sneeuwVlok;
MAEvent event;

//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth 		= EXTENT_X( screenSize );
	screenHeight		= EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte 	= 30;
	this->size			= 10;

	//maak een nieuwe sneeuwman
	sneeuwMan 	= new SneeuwMan( screenWidth / 2, screenHeight-sneeuwHoogte - 50,50,50);
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{

	//for(int i ; i < 100;i++)
	//{
	SneeuwVlok* sneeuwvlok 	= new SneeuwVlok( rand()% screenWidth + 1, 0,rand()%10+8);
	this->sneeuwVlokArray.add(sneeuwvlok);			// ARRRRRRRRAY

	//}

	//Loop door array->verwijder sneeuwvlokken die status DOOD zijn.


	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			{
				this->sneeuwMan->move( -6,0);	//beweeg sneeuwman -6 pixels
			}

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			{
				this->sneeuwMan->move( 6,0 );		//beweeg sneeuwman 6 pixels
			}

		//kijk voor up toets
				if( key == MAKB_UP )
					{
						this->sneeuwMan->move( 0,6 );		//beweeg sneeuwman 6 pixels
					}

		//kijk voor down toets
			if( key == MAKB_DOWN )
			{
				this->sneeuwMan->move( 0,-6 );		//beweeg sneeuwman 6 pixels
			}
	}

	//TODO: laat alle sneeuwvlokken vallen

	SneeuwVlok* vlok;

	for (MAUtil::Vector<SneeuwVlok*>::iterator itr = sneeuwVlokArray.begin();itr!= sneeuwVlokArray.end();
	itr++)
	{
		vlok = *itr;
		vlok->fall(screenHeight - this->sneeuwHoogte);

		if(vlok->isDead())	{
			sneeuwVlokArray.remove(itr);
			delete vlok;
		}
	}
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	maSetColor( 0x000000 );																	// zet de kleur op zwart
	maFillRect(0, screenHeight-sneeuwHoogte,screenWidth,3);

	//TODO: teken de sneeuwman

	sneeuwMan->draw();

	//TODO: teken alle sneeuwvlokken

	//Loop door array en teken sneeuwvlokken!

	SneeuwVlok* vlok;

	for (MAUtil::Vector<SneeuwVlok*>::iterator itr = sneeuwVlokArray.begin();itr!= sneeuwVlokArray.end();
	itr++)
	{
		vlok = *itr;
		vlok->draw();
	}


}

;
