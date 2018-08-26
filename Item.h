#ifndef STANDALONE_ITEM_H
#define STANDALONE_ITEM_H

class Item;

#include "Modifier.h"

class Item : Ability
{
public:
    int GetLevel();
};


#endif //STANDALONE_ITEM_H
