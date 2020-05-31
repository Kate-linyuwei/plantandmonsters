#ifndef MONSTER_H
#define MONSTER_H
#include"defenobj.h"

class monster : public defenobj
{
public:
    monster():defenobj("monster1",700,300){}//空构造函数用于new
    monster(string name1,int xx,int yy);//构造函数
    void move();//怪物移动

};

#endif // MONSTER_H
