#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <QPainter>
#include<QtMultimedia/QMediaPlayer>
#include"defenobj.h"
#include"bullet.h"
#include"monster.h"
#include"player.h"
class world
{
public:
    world();
    void originset();//初始设置塔和怪
    void addmonster0(int xx,int yy,int type);//添加怪物
    void monstermove0();//怪物移动
    void addbullet0();//添加子弹
    void bulletmove0();//子弹移动
    void painting(QPainter*p);//根据向量画出所有
    void rules();//规则说明
    void getorder(int type);//得到命令
private:
    vector<defenobj*>towers;//塔向量
    vector<bullet*>bullets;//子弹向量
    vector<monster*>monsters;//怪物向量
    player play;//玩家
};

#endif // WORLD_H
