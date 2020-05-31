#include "defenobj.h"
#include"icon.h"
#include"bullet.h"
#include<QtMultimedia/QMediaPlayer>
defenobj::defenobj(string name, int xx, int yy):_icon(_icon.matchicon(name))
{
    this->_name=name;
    this->_x=xx;
    this->_y=yy;
    this->_blood=2;
\
}//构造函数
void defenobj::reset(string name, int xx, int yy){
    this->_name=name;
    this->_x=xx;
    this->_y=yy;
    this->_icon=_icon.matchicon(name);
    this->_blood=2;
}//重设函数

defenobj::defenobj(defenobj &obj0):_icon(_icon.matchicon(obj0._name))
{
    this->_name=obj0._name;
    this->_x=obj0._x;
    this->_y=obj0._y;
    this->_pic=obj0._pic;
    this->_blood=2;
}//复制构造函数
void defenobj::death()
{
    QMediaPlayer * eaten=new QMediaPlayer;//创建QMediaPlayer指针
    eaten->setMedia(QUrl::fromLocalFile(":/music/sound of eaten.mp3"));//选择声音
    eaten->setVolume(20);//设置音效
    eaten->play();//播放

}
void defenobj::paint(QPainter *p)
{

    QImage allmodel;
    allmodel.load(":/picture/model.jpg");//引入整张模板
    this->_pic=allmodel.copy(this->_icon.getpicx()*32,this->_icon.getpicy()*32,this->_icon.getpicw()*32,this->_icon.getpich()*32);
    //得到对应截图
    p->drawImage(this->_x,this->_y,this->_pic);//画出对应图片
}
bullet *defenobj::creatbullet(){
    bullet* bul=new bullet;//创建子弹
    bul->reset(this->getX(),this->getY());//重设bullet
    return bul;//返回指针

}
