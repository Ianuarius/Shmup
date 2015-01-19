#include "Level.h"

Level::Level()
{
	result = levelDocument.load_file("spaceTest.tmx");

	if(!result)
	{
		std::cout << "Load result: " << result.description() << ", mesh name: " << levelDocument.child("mesh").attribute("name").value() << std::endl;
	}

/*
	std::string source = "<mesh name='sphere'><bounds>0 0 1 1</bounds></mesh>";
	source.c_str();*/
}

Level::~Level()
{
	
}

void Level::loadLevel()
{

	levelHeight = atoi(levelDocument.child("map").attribute("height").value());
	printf ("%d",levelHeight);
	pugi::xml_node node = levelDocument.child("map").child("layer").child("data");
	
	
	for (pugi::xml_node_iterator iterator = node.begin(); iterator != node.end(); ++iterator) 
	{
		for (int i = 0;i <levelHeight;++i)
		{
			printf(" %s", iterator->attribute("gid").value());
		}
		printf("\n");
	}
	
	/*
	for (pugi::xml_node tool = doc.child("Tool"); tool; tool = tool.next_sibling("Tool"))
	{
		std::cout << "Tool " << tool.attribute("Filename").value();
		std::cout << ": AllowRemote " << tool.attribute("AllowRemote").as_bool();
		std::cout << ", Timeout " << tool.attribute("Timeout").as_int();
		std::cout << ", Description '" << tool.child_value("Description") << "'\n";
	}
*/
}