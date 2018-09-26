#ifndef STANDALONE_MAP_H
#define STANDALONE_MAP_H

#include <string>

using namespace std;

class Map
{
public:
    Map(string name, unsigned int width, unsigned int height);
    ~Map();
    Map(Map& map);

public:
    signed char GetHeight(int width, int height);

// Texture
public:
    int GetTextureId(unsigned char layerId);
    void SetTextureId(unsigned char layerId, int textureId);
#define MAP_LAYER_MAX 8
};


#endif //STANDALONE_MAP_H
