#include "ironbullet.h"
#include"bullet.h"
ironbullet::ironbullet(int xx, int yy)
{
    this->_name="ironbullet";
    this->_bulx=xx;
    this->_buly=yy;//设置名字和坐标
    this->_bulicon=_bulicon.matchicon("ironbullet");//更改子弹图片
}
