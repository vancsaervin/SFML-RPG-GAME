#pragma once

#include "Tile.h"

class TileMap
{
private:
	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector< std::vector< Tile* > > > map;
	sf::Texture tileSheet;
	std::string texture_file;

public:
	TileMap(float gridSize, unsigned width, unsigned height, std::string texture_file);
	virtual ~TileMap();

	//Accessors
	const sf::Texture* getTileSheet() const;

	//Functions
	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);

	void update();
	void render(sf::RenderTarget& target);

	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
};

