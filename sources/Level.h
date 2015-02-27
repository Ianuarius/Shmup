#ifndef __LEVEL_H_DEFINED__
#define __LEVEL_H_DEFINED__

#include <string>
#include <vector>
#include "SDL.h"
#include "PugiXML.h"
#include "Window.h"
#include "Entity.h"
#include "Sprite.h"
#include "Camera.h"
#include "Texture.h"
#include "Animation.h"
#include "AI.h"

struct levelTrigger {
	// X Position where the trigger is triggered
	int spawnTile;
	// How many enemies to spawn
	int enemyCount;
	// Enemy type, currently string, may need to change to something
	std::string enemyType;
	// Y position where the trigger spawns enemies
	int spawnHeight;
};

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

		int levelWidth, levelHeight;
		int tileSize;

		Camera camera;

		Texture background;
		int bgScrollingOffset;

		Window *window;
		std::vector<std::vector<int>> levelData;
		std::vector<levelTrigger> triggers;
};

#endif //__LEVEL_H_DEFINED__