#ifndef SNOWSOILBUL_H
#define SNOWSOILBUL_H
#include"soilbullet.h"

class snowsoilbul : public soilbullet
{
public:
    snowsoilbul(int xx,int yy);
    bool stepback()const{return true;}//能够让怪物后退
};

#endif // SNOWSOILBUL_H
