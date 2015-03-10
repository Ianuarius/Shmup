#include "Level.h"

Level::Level(Window *window, EntityCollection<Enemy> *collection, EnemyFactory *factory):
	window(window),
	collection(collection),
	factory(factory),
	bgScrollingOffset(0),
	camera(256, 240),
	background(window, "kaupunki_tausta.png")
{
	camera.setSpeed(2);
	background_width = background.getWidth();
}

Level::~Level()
{ }

void Level::load(std::string level_name)
{
	// Loads the level document
	result = levelDocument.load_file(level_name.c_str());

	if (!result) {
		printf("Failed to load level %s.\n", level_name);
		return;
	}

	// Level size stuff
	tileSize = atoi(levelDocument.child("map").attribute("tilesize").value());
	levelWidth = atoi(levelDocument.child("map").attribute("width").value());
	levelHeight = atoi(levelDocument.child("map").attribute("height").value());

	// Get node which contains tileids
	tileNode = levelDocument.child("map").child("layer").child("data");

	// Load level background
	levelTileSheet = new Sprite(window, "512x512_kaupunki_tileset.png", tileSize, tileSize);

	int iteratorCount = 0;
	std::vector<int> levelRow;
	std::vector<int> enemySpawnRow;

	// Go through tile-nodes
	for(pugi::xml_node_iterator iterator = tileNode.begin();
		iterator != tileNode.end();
		++iterator)
	{
		iteratorCount++;

		// Add tile id to 
		int gid = atoi(iterator->attribute("gid").value());
		levelRow.push_back(gid);
		
		// NOTE(juha): Kun päästään kentän loppuun, vaihdetaan riviä.
		if (iteratorCount % levelWidth == 0)
		{
			levelData.push_back(levelRow);
			levelRow.clear();
		}
	}

	// Get enemy spawn regions
	enemySpawn = levelDocument.child("map").child("objectgroup");
	iteratorCount = 0;

	// Go through enemyspawn triggers
	for(pugi::xml_node_iterator iterator = enemySpawn.begin();
		iterator != enemySpawn.end();
		++iterator)
	{
		levelTrigger trigger;
		iteratorCount++;

		// Get X-position
		trigger.spawnTile = atoi(iterator->attribute("x").value());

		// Get trigger properties
		pugi::xml_node properties = iterator->child("properties");

		for(pugi::xml_node_iterator it = properties.begin();
			it != properties.end();
			++it)
		{
			if (strcmp(it->attribute("name").value(), "enemyCount") == 0) {
				trigger.enemyCount = atoi(it->attribute("value").value());
			}

			if (strcmp(it->attribute("name").value(), "enemyType") == 0) {
				trigger.enemyType = atoi(it->attribute("value").value());
			}

			if (strcmp(it->attribute("name").value(), "spawnHeight") == 0) {
				trigger.spawnHeight = atoi(it->attribute("value").value());
			}
		}

		triggers.push_back(trigger);
	}
}

void Level::update() {
	// NOTE(jouni&&karlos): Liikuttaa kameraa jos kenttä ei oo vielä loppunu
	if (camera.getX() < levelWidth*tileSize)
	{
		for (std::vector<levelTrigger>::iterator it = triggers.begin();
		it != triggers.end();
		++it) {
			if (camera.getX() >= it->spawnTile) {
				launchTrigger((*it));
				triggers.erase(it);
				break;
			}
		}
		camera.update();
	}

	//Scroll background
	--bgScrollingOffset;
	if(bgScrollingOffset < -background_width)
	{
		bgScrollingOffset = 0;
	}
}

// TODO(jouni): Muuttujaksi kameran X
void Level::render()
{
	background.render(bgScrollingOffset, 0);
	background.render(bgScrollingOffset + background_width, 0);
	
	std::vector<std::vector<int>>::iterator row;
	std::vector<int>::iterator col;

	for (row = levelData.begin(); row != levelData.end(); ++row) {
		for (col = row->begin(); col != row->end(); ++col) {
			int X = col - row->begin();
			int Y = row - levelData.begin();
			levelTileSheet->setIndex(*col-1);
			levelTileSheet->render(X*tileSize - camera.getX(), Y*tileSize);
		}
	}
}

// In pixels
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

void Level::launchTrigger(levelTrigger trigger) {
	for (int i = 0; i < trigger.enemyCount; i++)
	{
		Enemy enemy = factory->spawn(trigger.enemyType, trigger.spawnHeight);
		enemy.sinePattern(i % 2);
		enemy.setX(levelWidth + (i *20));
		enemy.setY(tileSize * trigger.spawnHeight);
		enemy.speed(2);
		collection->push(enemy);
	}
}

bool Level::collides(Entity *entity)
{
	int hbX;
	int hbY;

	// Palauttaa hitboxin vasemman yläkulman tilen
	hbX = entity->hitbox.x;
	hbY = entity->hitbox.y;
	printf("Hitbox %d/%d\n", entity->hitbox.x, entity->hitbox.y);
	printf("GETTILE: %d\n", getTile(hbX, hbY));

	if(getTile(hbX, hbY) > 0)
	{
		return true;
	}

	// Palauttaa hitboxin oikean yläkulman tilen
	hbX = entity->hitbox.x + entity->hitbox.w;
	hbY = entity->hitbox.y;

	if(getTile(hbX, hbY) > 0){
		return true;
	}

	// Palauttaa hitboxin vasemman alakulman tilen
	hbX = entity->hitbox.x + entity->hitbox.w;
	hbY = entity->hitbox.y + entity->hitbox.h;

	if(getTile(hbX, hbY) > 0){
		return true;
	}

	// Palauttaa hitboxin oikean alakulman tilen
	hbX = entity->hitbox.x;
	hbY = entity->hitbox.y + entity->hitbox.h;

	if(getTile(hbX, hbY) > 0){
		return true;
	}
	
	return false;
}