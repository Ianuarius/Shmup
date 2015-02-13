#include "Level.h"

Level::Level(Window *window):
	window(window),
	bgScrollingOffset(0),
	camera(256, 240),
	background(window, "background.png")
{
	camera.setSpeed(2);
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
}

// TODO(jouni): Muuttujaksi kameran X
void Level::renderLevel()
{
	// NOTE(jouni&&karlos): Liikuttaa kameraa jos kenttä ei oo vielä loppunu
	if (camera.getX() < levelWidth*tileSize)
	{
		camera.update();
	}

	int background_width;
	background_width = background.getWidth();

	//Scroll background
	--bgScrollingOffset;
	if(bgScrollingOffset < -background_width)
	{
		bgScrollingOffset = 0;
	}

	background.render(bgScrollingOffset, 0);
	background.render(bgScrollingOffset + background_width, 0);
	
	Sprite levelTileSheet(window, "pengsheet.png", tileSize, tileSize);
	std::vector<std::vector<int>>::iterator row;
	std::vector<int>::iterator col;

	for(row = levelData.begin(); row != levelData.end(); ++row) {
		for(col = row->begin(); col != row->end(); ++col) {
			int X = col - row->begin();
			int Y = row - levelData.begin();
			levelTileSheet.render(*col-1, X*tileSize - camera.getX(), Y*tileSize);
		}
	}
}

int Level::getLevelWidth()
{
	return levelWidth*tileSize;
}

int Level::getTile(int x, int y)
{
	if (y >= 0 &&
		x >= 0 &&
		y < levelData.size()*tileSize &&
		x < levelData[0].size()*tileSize)
	{
		return (levelData[y/tileSize][(camera.getX()+x)/tileSize]);
	}

	return 0;
}