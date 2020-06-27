#include "monster.h"
#include"defenobj.h"
int monster::bornblood=2;//初始2滴血
monster::monster(string name1, int xx, int yy):defenobj(name1,xx,yy){
    this->_blood=bornblood;//设置初始血量
}
void monster::move()
{
this->_x-=32*2;//移动一格
}
