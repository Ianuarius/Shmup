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

	levelWidth = atoi(levelDocument.child("map").attribute("width").value());
	tileNode = levelDocument.child("map").child("layer").child("data");

	int iteratorCount = 0;
	std::vector<int> levelRow;

	// NOTE(juha): Käydään tmx-tiedoston tile-nodet läpi.
	for(pugi::xml_node_iterator iterator = tileNode.begin();
		iterator != tileNode.end();
		++iterator) 
	{
		iteratorCount++;

		int gid = atoi(iterator->attribute("gid").value());
		
		levelRow.push_back(gid);
		
		// NOTE(juha): Kun päästään kentän loppuun, vaihdetaan riviä.
		if (iteratorCount % levelWidth == 0)
		{
			levelData.push_back(levelRow);
			levelRow.clear();
		}
	}
	// SDL_Rect testiCrop;
	// int tileNro = 3;

	// renderLevel(null);
}

// TODO(jouni): Muuttujaksi kameran X
void Level::renderLevel(SDL_Rect *camera)
{
	// IMPORTANT(juha): Harjoitus tekee ninjoja
	// SEMI-IMPORTANT (Karlos): sekä samuraita. Joskus.
	Sprite levelTileSheet(window, "pengsheet.png", tileSize, tileSize);
	std::vector<std::vector<int>>::iterator row;
	std::vector<int>::iterator col;

	for(row = levelData.begin(); row != levelData.end(); ++row) {
		for(col = row->begin(); col != row->end(); ++col) {
			int X = col - row->begin();
			int Y = row - levelData.begin();
			levelTileSheet.render(*col-1, X*tileSize - camera->x, Y*tileSize);
		}
	}
}

int Level::getLevelWidth()
{
	return levelWidth*tileSize;
}

int Level::getTile(int x, int y)
{
	//TODO(Kalle): KORJAAN TÄMÄN VIRHEENTAKRASTUKSEN ENSIKEERRALLAA
	if (x >= 0 && y >= 0 && x <levelData[0].size()*tileSize && y <= levelData.size()*tileSize) {
		return (levelData[y/tileSize][x/tileSize]);
	} else {
		return 0;
	}

}

// TODO(juha): render(), joka kutsuu jokaisen levelin palikan kohdalla windowin renderöijää
// TODO(juha): taulukko kaikista eri gid:eistä, jotka sitten yhdistetään eri spriteihin
