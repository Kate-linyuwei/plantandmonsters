#include "soilbullet.h"
#include"bullet.h"
soilbullet::soilbullet(int xx, int yy)
{
    this->_name="soilbullet";
    this->_bulx=xx;
    this->_buly=yy;//设置名字和坐标
    this->_bulicon=_bulicon.matchicon("soilbullet");//更改子弹图片
}

void soilbullet::move(){
    this->_bulx=this->_bulx+32*4;//泥土子弹移动速度更快
}
