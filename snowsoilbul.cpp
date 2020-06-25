#include "snowsoilbul.h"

snowsoilbul::snowsoilbul(int xx, int yy):soilbullet(xx,yy)
{
    this->_name="snowsoilbullet";
    this->_bulx=xx;
    this->_buly=yy;//设置名字和坐标
    this->_bulicon=_bulicon.matchicon("snowsoilbullet");//更改子弹图片
}
