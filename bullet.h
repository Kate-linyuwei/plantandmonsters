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
    void reset(int xx, int yy);//重新设置位置
    void paint(QPainter*p);//画出子弹
    void move();//子弹移动
    int getX() const{
        return this->_bulx;
    }
    int getY() const{
        return this->_buly;
    }//返回坐标
protected:
    string _name;
    int _bulx;
    int _buly;//名字和坐标
   QImage _bulpic;//图片
   icon _bulicon;



};

#endif // BULLET_H
