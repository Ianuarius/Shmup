#ifndef LEVEL_H_DEFINED
#define LEVEL_H_DEFINED

#include <string>
#include <iostream>
#include "SDL.h"
#include "PugiXML.h"
#include "Window.h"
#include "Sprite.h"

class Level
{
public:
	Level(Window *window);
	~Level();
	void loadLevel();

private:
	pugi::xml_document levelDocument;
	pugi::xml_parse_result result;
	int levelWidth;
	Window *window;
	int tileSize;
};

#endif //__LEVEL_H_DEFINED__