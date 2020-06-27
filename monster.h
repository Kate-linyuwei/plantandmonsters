#ifndef MONSTER_H
#define MONSTER_H
#include"defenobj.h"

class monster : public defenobj
{
public:
    monster():defenobj("monster1",700,300){}//空构造函数用于new
    monster(string name1,int xx,int yy);//构造函数
    void move();//怪物移动
    void backstep(){this->_x=this->_x+32*8;}//怪物被打退
    static int bornblood;//初始血量，用于加大难度
};

#endif // MONSTER_H
