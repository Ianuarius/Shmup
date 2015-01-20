#include "Level.h"

Level::Level(Window *window):
	window(window)
{


}

Level::~Level()
{
	
}

void Level::loadLevel()
{
	result = levelDocument.load_file("spaceTest.tmx");

	tileSize = atoi(levelDocument.child("map").attribute("tilewidth").value());

	if(!result)
	{
		// NOTE(juha): Log the shit out of things.

		// std::cout << "Load result: " << result.description() << ", mesh name: " << 
		//	levelDocument.child("mesh").attribute("name").value() << std::endl;
	}

	int iteratorCount = 0;
	int X = 0;
	int Y = 0;

	levelWidth = atoi(levelDocument.child("map").attribute("width").value());
	pugi::xml_node tileNode = 
		levelDocument.child("map").child("layer").child("data");

	// NOTE(juha): Käydään tmx-tiedoston tile-nodet läpi. Vaihdetaan riviä joka
	// kerta kun tilejä on tulostettu kentän leveyden verran.
	for(pugi::xml_node_iterator iterator = tileNode.begin();
		iterator != tileNode.end();
		++iterator) 
	{
		
		iteratorCount++;

		switch(atoi(iterator->attribute("gid").value()))
		{
		case 30:
			window->drawRect(X*tileSize, Y*tileSize, tileSize, tileSize, Color("green"));
			break;
		case 7:
			window->drawRect(X*tileSize, Y*tileSize, tileSize, tileSize, Color("red"));
			break;
		case 10:
			window->drawRect(X*tileSize, Y*tileSize, tileSize, tileSize, Color("magenta"));
			break;
		default:
			window->drawRect(X*tileSize, Y*tileSize, tileSize, tileSize, Color("white"));
		}
		
		X++;
		// printf(" %s", iterator->attribute("gid").value());
		
		if (iteratorCount % levelWidth == 0)
		{
			// printf("[%d]asd\n", iteratorCount);
			Y++;
			X = 0;
		}
	}
}


// TODO(juha): render(), joka kutsuu jokaisen levelin palikan kohdalla windowin renderöijää
// TODO(juha): taulukko kaikista eri gid:eistä, jotka sitten yhdistetään eri spriteihin
