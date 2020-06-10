#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <QPainter>
#include<QMediaPlayer>
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
    void changeline(int ord);//改变行数
    void endcheck();//检查怪物是否突破房子，结束游戏
    bool getlosecheck()const{return losecheck;}//返回是否失败
    void changelose(){losecheck=true;}//更改输赢状态
    int getgold()const{return this->play.getmoney();}//得到金币
private:
    vector<defenobj*>towers;//塔向量
    vector<bullet*>bullets;//子弹向量
    vector<monster*>monsters;//怪物向量
    player play;//玩家
    static int Line;//行数，取余为第几行
    static  int linetower[3];//每一行的塔数，用于确定放新塔的位置
    static bool losecheck;//是否输掉
};

#endif // WORLD_H
