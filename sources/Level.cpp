#include "Level.h"

Level::Level(Window *window):
	window(window)
{


}

Level::~Level()
{
	
}

void Level::loadLevel(std::string level_name)
{
	result = levelDocument.load_file(level_name.c_str());

	if (!result) {
		printf("Levelin %s lataaminen epäonnistui.", level_name);
		return;
	}

	tileSize = atoi(levelDocument.child("map").attribute("tilewidth").value());

	if(!result)
	{
		// NOTE(juha): Log the shit out of things.
	}

	int iteratorCount = 0;
	int X = 0;
	int Y = 0;

	levelWidth = atoi(levelDocument.child("map").attribute("width").value());
	pugi::xml_node
		tileNode = levelDocument.child("map").child("layer").child("data");

	
	Sprite testi(window, "tmw_desert_spacing16.png", tileSize, tileSize);
	// SDL_Rect testiCrop;
	// int tileNro = 3;

	// NOTE(juha): Käydään tmx-tiedoston tile-nodet läpi.
	for(pugi::xml_node_iterator iterator = tileNode.begin();
		iterator != tileNode.end();
		++iterator) 
	{
		iteratorCount++;

		int gid = atoi(iterator->attribute("gid").value());
		testi.render(gid-1, X*tileSize, Y*tileSize);
		
		X++;
		
		// NOTE(juha): Kun päästään kentän loppuun, vaihdetaan riviä.
		if (iteratorCount % levelWidth == 0)
		{
			Y++;
			X = 0;
		}
	}
}

// TODO(juha): render(), joka kutsuu jokaisen levelin palikan kohdalla windowin renderöijää
// TODO(juha): taulukko kaikista eri gid:eistä, jotka sitten yhdistetään eri spriteihin
