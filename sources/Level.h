#ifndef LEVEL_H_DEFINED
#define LEVEL_H_DEFINED

#include <string>
#include <iostream>
#include "SDL.h"
#include "PugiXML.h"
#include "Window.h"
#include "Sprite.h"
#include <vector>

class Level
{
public:
	Level(Window *window);
	~Level();
	void loadLevel(std::string level_name);
	int getLevelWidth();
	void renderLevel(SDL_Rect *camera);
	int getTile(int x, int y);


private:
	pugi::xml_document levelDocument;
	pugi::xml_parse_result result;
	pugi::xml_node tileNode;

	int levelWidth;
	int tileSize;

	Window *window;
	std::vector<std::vector<int>> levelData;
};

#endif //__LEVEL_H_DEFINED__