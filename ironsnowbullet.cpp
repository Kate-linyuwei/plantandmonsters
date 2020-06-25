#include "ironsnowbullet.h"
#include"bullet.h"
ironsnowbullet::ironsnowbullet(int xx,int yy)
{
    this->_name="ironsnowbullet";
    this->_bulx=xx;
    this->_buly=yy;//设置名字和坐标
    this->_bulicon=_bulicon.matchicon("ironsnowbullet");//更改子弹图片
}
