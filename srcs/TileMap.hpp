#ifndef TILEMAP_HPP
# define TILEMAP_HPP

#include <string>
#include <iostream>
#include <map>
#include "raylib.h"

using namespace std;

class Tile
{
public:
    Texture2D texture;
    int midi;
    int midj;

    Tile();
    Tile(Image &img, int midi, int midj);
    ~Tile();
    
    void render(int x, int y);
};

class TileMap
{
public:
    string filepath;
    Image   img;
    map<string, Tile> tiles;

    TileMap(string filepath);
    ~TileMap();

    void addTile(string name, int i, int j, int di, int dj, int midi, int midj);
    Tile &getTile(string name);
    void init();
    void render(int x, int y, string name);
};

#endif
