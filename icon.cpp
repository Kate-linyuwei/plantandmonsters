#include "icon.h"
#include<map>
#include<iostream>
using namespace std;
pair<string,icon> pairArray[] =
{
    make_pair("redpalace",icon("redpalace",8,6,2,2)),
    make_pair("bluepalace",icon("bluepalace",10,6,2,2)),
    make_pair("soiltower",icon("soiltower",12,6,2,2)),
    make_pair("irontower",icon("irontower",14,6,2,2)),
    make_pair("snowpalace",icon("snowpalace",12,14,2,2)),
    make_pair("snowtower",icon("snowtower",14,14,2,2)),
    make_pair("monster1",icon("monster1",0,12,1,1)),
    make_pair("monster2",icon("monster2",8,2,1,1)),
    make_pair("bullet",icon("bullet",10,4,1,1)),
    make_pair("soilbullet",icon("soilbullet",7,11,1,1)),
    make_pair("ironbullet",icon("ironbullet",7,10,1,1)),
    make_pair("snowsoilbullet",icon("snowsoilbullet",15,2,1,1)),
    make_pair("ironsnowbullet",icon("ironsnowbullet",15,1,1,1))
}; //加入塔和怪物模板,和子弹


map<string,icon> icon::iconmap(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));
//创建模板icon,只对iconmap修改

icon::icon(string picn,int px,int py,int pw,int ph){
    this->_picname=picn;
    this->_picx=px;
    this->_picy=py;
    this->_picw=pw;
    this->_pich=ph;//构造函数传入参数
}

icon icon::matchicon(string picn){
    map<string,icon>::iterator searchname;//匹配名字的迭代器
    //找到匹配名字
    for(searchname=icon::iconmap.begin();searchname!=icon::iconmap.end();searchname++){
        if(searchname->first==picn)
            break; //找到匹配,停止
    }
    if(searchname==icon::iconmap.end())
        return icon("redpalace",8,6,2,2);//找不到时，自动为redpalace
    else
        return searchname->second;//找到匹配，返回对应icon
}
