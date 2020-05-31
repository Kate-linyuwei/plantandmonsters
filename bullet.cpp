#include "bullet.h"
#include<string.h>
#include<QImage>
#include"icon.h"
bullet::bullet(int xx, int yy):_bulicon(_bulicon.matchicon("bullet"))
{
    this->_name="bullet";
    this->_bulx=xx;
    this->_buly=yy;//设置名字和坐标
}
void bullet::reset( int xx, int yy){

    this->_name="bullet";
    this->_bulx=xx;
    this->_buly=yy;
    this->_bulicon=_bulicon.matchicon("bullet");//设置名字和坐标和图片

}
void bullet::paint(QPainter*p){

    QImage allmodel;
    allmodel.load(":/picture/model.jpg");//引入整张模板
    this->_bulpic=allmodel.copy(this->_bulicon.getpicx()*32,this->_bulicon.getpicy()*32,this->_bulicon.getpicw()*32,this->_bulicon.getpich()*32);
    //得到对应截图
    p->drawImage(this->_bulx,this->_buly,this->_bulpic);//画出对应图片
}
void bullet::move(){
    this->_bulx=this->_bulx+32;//移动一格
}
