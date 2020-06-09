#ifndef DEFENOBJ_H
#define DEFENOBJ_H

#include<QImage>
#include<string.h>

#include<QMediaPlayer>
#include<QPainter>
#include"icon.h"
#include"bullet.h"

class defenobj
{
public:
    defenobj(string name,int xx,int yy);//构造函数
    defenobj():_icon(icon("redpalace",8,6,2,2)){}//空构造函数用于new
    void reset(string name,int xx,int yy);//重新设置函数

    defenobj(defenobj &obj0);//复制构造
    virtual ~defenobj(){}//析构函数
    bullet* creatbullet();//制造子弹
    void death();//死去的声音
    void paint(QPainter*p);//画出对应图像
    void loseblood(){
        this->_blood--;
    }//被打失血
    int getblood()const{
        return this->_blood;
    }//返回血量
    int getX()const{
        return this->_x;
    }
    int getY()const{
        return this->_y;
    }//返回坐标
protected:
    string _name;//名字
    int _x;
    int _y;//位置坐标
    QImage _pic;//对应图片
    int _blood;//血量
    icon _icon;//图片对应类

};

#endif // DEFENOBJ_H
