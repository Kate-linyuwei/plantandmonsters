#ifndef IRONSNOWBULLET_H
#define IRONSNOWBULLET_H
#include"bullet.h"

class ironsnowbullet : public bullet
{
public:
    ironsnowbullet(int xx,int yy);//构造函数
    bool crosscheck()const{return true;}//能否穿透怪物
    bool stepback()const{return true;}//能够让怪物后退
};

#endif // IRONSNOWBULLET_H
