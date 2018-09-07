#ifndef STANDALONE_ITEM_H
#define STANDALONE_ITEM_H

#include "Modifier.h"
#include "Utils.h"

class Item : Ability
{
public:
    bool IsDropped() { return Utils::iequals(GetOwner()->GetName(), "dropped_item"); }

    virtual string GetDroppedModel() { return "present"; }
};


#endif //STANDALONE_ITEM_H
