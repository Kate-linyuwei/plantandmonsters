#include "monster.h"
#include"defenobj.h"
monster::monster(string name1, int xx, int yy):defenobj(name1,xx,yy){

}
void monster::move()
{
this->_x-=32*2;//移动一格
}
