#ifndef PLAYER_H
#define PLAYER_H
#include<string.h>
#include"defenobj.h"
#include"monster.h"

class player
{
public:
    player(){}
    defenobj* addnewobj(int xx,int yy,int type);//玩家在指定坐标添加指令对应塔
};

#endif // PLAYER_H
