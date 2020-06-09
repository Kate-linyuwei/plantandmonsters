#include "world.h"
#include"player.h"
#include<QMediaPlayer>
int world::Line=300;//初始化,300
int world::linetower[3]={0,0,0};//初始化每行都没塔
void world::changeline(int ord){
    if(ord==1)
        world::Line++;
    else
        world::Line--;
}//通过外部按键改变行
world::world()
{

}
void world::originset(){
    defenobj* obj=new defenobj;//创建指针，分配空间
    obj->reset("redpalace",256,300);
    world::linetower[0]++;
    //初始塔,并且在相应行数加上塔的数目

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
                delete(*b);//子弹打怪后失效,析构
                bullets.erase(b);//在子弹向量内清除
                if((*m)->getblood()<=0){
                    (*m)->death();//怪物没血，死去声音
                    delete (*m);//回收改怪物，析构
                    monsters.erase(m);//在向量内清除
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
    for(int i=0;i<m;i++){
        monsters.at(i)->move();
    }//依次移动
}
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



void world::getorder(int type){
    int countline=Line%3;//所在行数
    int counttower=linetower[countline];//所在行有多少个塔
    defenobj* tow;
    tow=this->play.addnewobj(256+counttower*64,300+countline*100,type);//得到创建新塔的返回指针
    this->towers.push_back(tow);
    world::linetower[countline]++;
    //加入列表,在该行增加塔数
}











