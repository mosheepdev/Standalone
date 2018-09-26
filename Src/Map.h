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

private:
    string _Name;
public:
    string GetName() { return _Name; }

private:
    unsigned int _Width, _Height;
public:
    unsigned int GetWidth() { return _Width; }
    unsigned int GetHeight() { return _Height; }

public:
    signed char GetHeight(int width, int height);

// Texture
#define MAP_LAYER_MAX 8
public:
    int GetTextureId(unsigned char layerId) { return _LayerTextureId[layerId]; };
    float GetTextureWeight(unsigned char layerId) { return _LayerTextureWeight[layerId]; };
    void SetTextureId(unsigned char layerId, int textureId);
    void SetTextureWeight(unsigned char layerId, float textureWeight);
    void SetTexture(unsigned char layerId, int textureId, float textureWeight);
private:
    int _LayerTextureId[MAP_LAYER_MAX];
    float _LayerTextureWeight[MAP_LAYER_MAX];
};


#endif //STANDALONE_MAP_H
