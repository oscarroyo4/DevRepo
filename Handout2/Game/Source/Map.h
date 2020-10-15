#ifndef __MAP_H__
#define __MAP_H__

#include "Module.h"
#include "List.h"
#include "Point.h"

#include "PugiXml\src\pugixml.hpp"

// L03: TODO 2: Create a struct to hold datarmation for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
struct TileSet
{
	SString				name;
	int					firstgid;
	int					margin;
	int					spacing;
	int					tile_width;
	int					tile_height;
	SDL_Texture*		texture;
	int					tex_width;
	int					tex_height;
	int					num_tiles_width;
	int					num_tiles_height;
	int					offset_x;
	int					offset_y;

};

// L03: TODO 1: Create a struct needed to hold the datarmation to Map node
struct Mapdata
{
	int					width;
	int					height;
	int					tile_width;
	int					tile_height;
	SDL_Color			background_color;
	List<TileSet*>		tilesets;
};

class Map : public Module
{
public:

    Map();

    // Destructor
    virtual ~Map();

    // Called before render is available
    bool Awake(pugi::xml_node& conf);

    // Called each loop iteration
    void Draw();

    // Called before quitting
    bool CleanUp();

    // Load new map
    bool Load(const char* path);

	bool LoadMap();
	bool LoadTileset(pugi::xml_node&, TileSet*);

    // L03: TODO 1: Add your struct for map data as public for now
	Mapdata data;

private:

    pugi::xml_document mapFile;
    SString folder;
    bool mapLoaded;
};

#endif // __MAP_H__