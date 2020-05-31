#ifndef ICON_H
#define ICON_H
#include<string>
#include<map>
#include<iostream>
using namespace std;//问题一，map不被识别，若无std

class icon
{
public:
    icon(string picn,int px,int py,int pw,int ph);//构造函数，物体名字，图片本身坐标，截取的图片长宽
    icon matchicon(string picn);//根据名字找到匹配icon，并且返回
    static map<string,icon> iconmap;//模板icon
    int getpicx()const{
        return this->_picx;
    }
    int getpicy()const{
        return this->_picy;
    }
    //得到坐标值
    int getpicw()const{
        return this->_picw;
    }
    int getpich()const{
        return this->_pich;
    }//得到长和宽
private:
    string _picname;//图片名称
    int _picx;
    int _picy;//图片本身坐标
    int _picw;
    int _pich;//截取的图片长宽


};

#endif // ICON_H
