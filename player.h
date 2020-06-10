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
    void earn();//打死怪物，得到金币
    void pay();//买塔，花钱
    int getmoney()const{return money;}//得到金币信息
private:
    static int money;//钱
};

#endif // PLAYER_H
