#ifndef STANDALONE_PLAYER_H
#define STANDALONE_PLAYER_H

#include <string>

using namespace std;

class Player
{
public:
    int GetUniqueId() { return 0; }

    string GetLoginName() { return "asdf"; }

    string GetDisplayName() { return "Asdf"; }

};


#endif //STANDALONE_PLAYER_H
