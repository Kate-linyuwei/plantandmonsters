#ifndef IRONBULLET_H
#define IRONBULLET_H
#include"bullet.h"

class ironbullet :virtual public bullet
{
public:
    ironbullet(int xx,int yy);
    bool crosscheck()const{return true;}//能否穿透怪物
};

#endif // IRONBULLET_H
