#ifndef __LEVEL_H_DEFINED__
#define __LEVEL_H_DEFINED__

#include <string>
#include <iostream>
#include <vector>
#include "SDL.h"
#include "PugiXML.h"
#include "Window.h"
#include "Sprite.h"
#include "Camera.h"
#include "Texture.h"

class Level
{
public:
	Level(Window *window);
	~Level();

	void loadLevel(std::string level_name);
	void renderLevel();
	
	int getTile(int x, int y);
	int getLevelWidth();

private:
	pugi::xml_document levelDocument;
	pugi::xml_parse_result result;
	pugi::xml_node tileNode;
	pugi::xml_node enemySpawn;

	int levelWidth;
	int tileSize;

	Camera camera;

	Texture background;
	int bgScrollingOffset;

	Window *window;
	std::vector<std::vector<int>> levelData;
};

#endif //__LEVEL_H_DEFINED__