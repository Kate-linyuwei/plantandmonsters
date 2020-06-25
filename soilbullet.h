#ifndef SOILBULLET_H
#define SOILBULLET_H
#include<string.h>
#include<QImage>
#include<QPainter>
#include"icon.h"
#include<QMediaPlayer>
#include<bullet.h>

class soilbullet : virtual public bullet
{
public:
    soilbullet(int xx,int yy);//构造函数
    void move();//移动
};

#endif // SOILBULLET_H
