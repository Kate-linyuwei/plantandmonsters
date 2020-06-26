#include "world.h"
#include"player.h"
#include<QMediaPlayer>
#include <QPainter>
bool world::losecheck=false;//初始没有输
world::world()
{

}
void world::originset(){
    defenobj* obj=new defenobj;//创建指针，分配空间
    obj->reset("redpalace",256,300);
    //初始塔,并且加上塔的数目

    bullet* bul=new bullet;
    bul=obj->creatbullet();
    //初始子弹

    monster*mons=new monster;
    mons->reset("monster1",704,300);

    //初始怪

    towers.push_back(obj);
    bullets.push_back(bul);
    monsters.push_back(mons);//在向量中新增塔，子弹和怪


}
void world::painting(QPainter*p){
    int n=towers.size();//获取个数
    for(int i=0;i<n;i++){
        towers.at(i)->paint(p);//逐个画出
    }
    //画塔
    int m=bullets.size();//获取个数
    for(int j=0;j<m;j++){
        bullets.at(j)->paint(p);//逐个画出
    }
    //画子弹
    int l=monsters.size();//获取个数
    for(int k=0;k<l;k++){
        monsters.at(k)->paint(p);//逐个画出
    }
    //画怪

}
void world::rules(){

    vector<monster*>::iterator m;//怪物迭代器
    vector<defenobj*>::iterator t;//塔迭代器
    vector<bullet*>::iterator b;//子弹迭代器
    for(m=monsters.begin();m<monsters.end();m++){
        for(b=bullets.begin();b<bullets.end();b++){
            if((*m)->getX()==(*b)->getX()&&(*m)->getY()==(*b)->getY()){
                (*m)->loseblood();//怪遇到子弹，降低血量
                if((*b)->crosscheck()==false){
                    delete(*b);//子弹打怪后失效,析构
                    bullets.erase(b);//在子弹向量内清除
                }//不具备穿透功能的子弹会遇怪消失
                if((*b)->stepback()==true){
                    (*m)->backstep();//能打退怪物的子弹实现功能
                }
                if((*m)->getblood()<=0){
                    (*m)->death();//怪物没血，死去声音
                    delete (*m);//回收改怪物，析构
                    monsters.erase(m);//在向量内清除
                    this->play.earn();//金币增加100
                }
            }
        }
        //子弹与怪
        for(t=towers.begin();t<towers.end();t++){
            if((*m)->getX()==(*t)->getX()&&(*m)->getY()==(*t)->getY()){
                (*t)->loseblood();//塔遇到怪失血
                if((*t)->getblood()<=0){//塔没血了
                    (*t)->death();//塔摧毁的声音
                    delete (*t);//塔消失，析构
                    towers.erase(t);//在塔向量内清除该塔
                }
            }
        }
        //塔与怪

    }
}

void world::endcheck(){
    vector<monster*>::iterator m;//怪物迭代器
    for(m=monsters.begin();m<monsters.end();m++){
        if((*m)->getX()<=232){
            //有怪物突破防线
            this->changelose();
            //更改输赢状态

            QMediaPlayer * lose=new QMediaPlayer;//创建QMediaPlayer指针
            lose->setMedia(QUrl("qrc:/music/lose.mp3"));//选择失败声音
            lose->setVolume(30);//设置音效
            lose->play();//播放
            //失败的声音

        }
    }

    vector<bullet*>::iterator b;//子弹迭代器
    for(b=bullets.begin();b<bullets.end();b++){
        if((*b)->getX()>700){
            delete(*b);//子弹超出界面后失效,析构
            bullets.erase(b);//在子弹向量内清除
        }
    }
    //清除无用的子弹，节省空间
}
void world::addmonster0(int xx, int yy, int type){
    if(type==1){
        monster* newmon=new monster;
        newmon->reset("monster1",xx,yy);
        this->monsters.push_back(newmon);
    }
    else{
        monster* newmon=new monster;
        newmon->reset("monster2",xx,yy);
        this->monsters.push_back(newmon);
    }//根据类型产生怪物
}
void world::monstermove0(){
    int m=monsters.size();
    int t=towers.size();//塔的数量，用于判断塔有没有挡住
    for(int i=0;i<m;i++){
        int flag=0;//塔有没挡住
        for(int j=0;j<t;j++){
            if((monsters[i]->getX()==towers[j]->getX())&&(monsters[i]->getY()==towers[j]->getY())){
                flag=1;
                break;//遇到塔，停下，不再前进
            }
        }
        if(flag==0){
            monsters.at(i)->move();//没被挡住才要移动
        }
    }
}//依次移动

void world::addbullet0(){
    int t=towers.size();
    for(int j=0;j<t;j++){
        bullet*bu=towers.at(j)->creatbullet();
        this->bullets.push_back(bu);
    }//添加子弹
}
void world::bulletmove0(){
    int b=bullets.size();
    for(int k=0;k<b;k++){
        bullets.at(k)->move();
    }
}//子弹依次移动



void world::getorder(int type, int xx, int yy){
    int flag=0;//判断是否符合买塔条件
    if((type<=3)&&(this->play.getmoney()>=100)){
        flag=1;//符合条件
        this->play.pay(100);//买前三种塔花金币100
    }
    else if(type>3&&type<=5&&(this->play.getmoney()>=150)){
        flag=1;//符合条件
        this->play.pay(150);//买第4或5种塔花150金币
    }
    else if(type==6&&(this->play.getmoney()>=200)){
        flag=1;
        this->play.pay(200);//符合条件买最后一种塔
    }
    else
        flag=0;//三种情况都不符合，不满足条件
    if(flag==1){
        defenobj* tow;//满足条件新增塔
        tow=this->play.addnewobj(xx,yy,type);//得到创建新塔的返回指针
        this->towers.push_back(tow);//加入新塔，放进向量中
    }
    else {//不满足条件放音乐提醒
        QMediaPlayer * nomoney=new QMediaPlayer;//创建QMediaPlayer指针
        nomoney->setMedia(QUrl("qrc:/music/nomoney.mp3"));//选择没钱的声音
        nomoney->setVolume(10);//设置音效
        nomoney ->play();//播放
    }

}
void world::removetower(int xx, int yy){
     vector<defenobj*>::iterator tow;//塔迭代器
    for(tow=towers.begin();tow<towers.end();tow++){
        if((*tow)->getX()==xx&&(*tow)->getY()==yy){
            delete (*tow);//拆除塔，析构
            towers.erase(tow);//在塔向量内清除
        }
    }
}










