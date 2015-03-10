#ifndef __LEVEL_H_DEFINED__
#define __LEVEL_H_DEFINED__

#include <vector>
#include "Window.h"
#include "Camera.h"
#include "PugiXML.h"
#include "Texture.h"
#include "Sprite.h"
#include "EntityCollection.h"
#include "EnemyFactory.h"
#include "Enemy.h"

class Level
{
	public:
		Level(Window *window, EntityCollection<Enemy> *collection, EnemyFactory *factory);
		~Level();

		void load(std::string level_name);
		void update();
		void render();
	
		int getTile(int x, int y);
		int getLevelWidth();
		bool collides(Entity *entity);

		struct levelTrigger {
			// X Position where the trigger is triggered
			int spawnTile;
			// How many enemies to spawn
			int enemyCount;
			// Enemy type, currently string, may need to change to something
			int enemyType;
			// Y position where the trigger spawns enemies
			int spawnHeight;
		};

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
		int background_width;

		Window *window;
		EntityCollection<Enemy> *collection;
		EnemyFactory *factory;

		Sprite *levelTileSheet;
		std::vector<std::vector<int>> levelData;
		std::vector<levelTrigger> triggers;

		void launchTrigger(levelTrigger enemyCount);
};

#endif //__LEVEL_H_DEFINED__