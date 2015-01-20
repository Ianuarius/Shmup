#ifndef LEVEL_H_DEFINED
#define LEVEL_H_DEFINED

#include <string>
#include <iostream>
#include "SDL.h"
#include "PugiXML.h"

class Level
{
public:
	Level();
	~Level();
	void loadLevel();

private:
	pugi::xml_document levelDocument;
	pugi::xml_parse_result result;
	int levelHeight;
};

#endif //__LEVEL_H_DEFINED__