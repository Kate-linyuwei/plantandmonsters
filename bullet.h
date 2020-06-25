#ifndef BULLET_H
#define BULLET_H
#include<string.h>
#include<QImage>
#include<QPainter>
#include"icon.h"
#include<QMediaPlayer>
class bullet
{
public:

    bullet(int xx,int yy);//构造函数
    bullet():_bulicon(icon("bullet",10,4,1,1)){}//空构造函数
    virtual void reset(int xx, int yy);//重新设置位置
    virtual void paint(QPainter*p);//画出子弹
    virtual void move();//子弹移动
    int getX() const{
        return this->_bulx;
    }
    int getY() const{
        return this->_buly;
    }//返回坐标
    virtual bool crosscheck()const{return false;}//是否能穿过怪物
    virtual bool stepback()const{return false;}//是否能让怪物退后
    virtual ~bullet(){}//虚析构

protected:
    string _name;
    int _bulx;
    int _buly;//名字和坐标
   QImage _bulpic;//图片
    icon _bulicon;



};

#endif // BULLET_H
