#include "TileMap.hpp"

Tile::Tile()
{
}

Tile::Tile(Image &img, int midi, int midj)
: midi(midi), midj(midj)
{
    texture = LoadTextureFromImage(img);
}

Tile::~Tile()
{
    UnloadTexture(texture);
}

void Tile::render(int x, int y)
{
    // std::cout << "mid x = " << -midi << " and y = " << midj << std::endl;
    std::cout << "RENDER AT x =  "<< (x - midj) *32 << " and y = " << (y + midi) * 32 << std::endl;

    DrawTexture(texture, (x - midj) *32, (y + midi) * 32, WHITE);
    // DrawTexture(texture, 50, 50, WHITE);
}

TileMap::TileMap(string filepath): filepath(filepath)
{
    img = LoadImage(filepath.c_str());
}

TileMap::~TileMap()
{
    UnloadImage(img);
}

void TileMap::addTile(string name, int i, int j, int height, int width, int midi, int midj)
{
    Rectangle rect;
    rect.x = (i+1 - height)*32.f;
    rect.y = j*32.f;
    rect.height = height*32.f;
    rect.width = width*32.f;

    std::cout << "les mids ;" << name << "; " << midi << " " << midj << "\n";
    
    Image croped = LoadImage(filepath.c_str());
    ImageCrop(&croped, rect);
    // Image croped = LoadImage("sprites/Character.png");
    cout << "RECT : " << rect.x << " " << rect.y << " " << rect.height << " " << rect.width << " " << midi << " " << midj << endl;

    Tile tile(croped, -midi * 32, midj * 32);
    tiles[name] = tile;
    UnloadImage(croped);
}

Tile &TileMap::getTile(string name)
{
    return tiles[name];
}

void TileMap::init()
{
    // nom, i, j, height, width, midi, midj
    addTile("bloc blanc", 1, 1, 2, 1, 0, 0);
    addTile("coffre ferme", 3, 1, 2, 1, 0, 0);
    addTile("coffre ouvert", 3, 2, 2, 1, 0, 0);
    addTile("porte ferme", 0, 5, 2, 3, 1, 0);
    addTile("panneau est", 3, 6, 1, 1, 0, 0);
    addTile("panneau ouest", 3, 9, 1, 1, 0, 0);
    addTile("grosse caisse", 5, 2, 2, 1, 0, 0);
    addTile("petite caisse", 5, 4, 2, 1, 0, 0);
    addTile("tonneau", 5, 6, 2, 1, 0, 0);
    addTile("pot1", 5, 8, 2, 1, 0, 0);
    addTile("pot2", 5, 10, 1, 1, 0, 0);
    addTile("pot3", 5, 12, 1, 1, 0, 0);
    addTile("tombe eteint1", 7, 2, 2, 1, 0, 0);
    addTile("tombe eteint2", 7, 5, 3, 1, 0, 0);
    addTile("tombe eteint3", 7, 7, 2, 1, 0, 0);
    addTile("tombe allume1", 8, 2, 2, 1, 0, 0);
    addTile("tombe allume2", 8, 5, 2, 1, 0, 0);
    addTile("tombe allume3", 8, 7, 2, 1, 0, 0);
    addTile("Autel", 11, 10, 3, 3, 1, 1);
    addTile("banc", 9, 1, 2, 2, 0, 0);
    addTile("grande Tombe", 9, 3, 2, 2, 0, 0);
}

void TileMap::render(int x, int y, string name)
{
    // std::cout << x << " " << y << " " << name << std::endl;

    tiles[name].render(x, y);
}