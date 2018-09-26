#include "Map.h"

Map::Map(string name, unsigned int width, unsigned int height) : _Name(name), _Width(width), _Height(height)
{
    // Clear Layer Textures (ID + Weight)
    for(unsigned char i = 0; i < MAP_LAYER_MAX; i++)
    {
        _LayerTextureId[i] = -1;
        _LayerTextureWeight[i] = 0.0f;
    }
};
