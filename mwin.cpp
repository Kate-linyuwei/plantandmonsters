#include "mwin.h"
#include "ui_mwin.h"


Mwin::Mwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mwin)
{
    ui->setupUi(this);
    myworld.originset();//设置初始塔怪
    timing=new QTimer(this);
    timing->setInterval(1000);//设置间隔1000ms
    timing->start();//开始计时
    connect(timing,SIGNAL(timeout()),this,SLOT(addmonster()));
    connect(timing,SIGNAL(timeout()),this,SLOT(monstermove()));
    connect(timing,SIGNAL(timeout()),this,SLOT(addbullet()));
    connect(timing,SIGNAL(timeout()),this,SLOT(bulletmove()));//将定时发生的移动和产生创建联系
    //connect(timing,SIGNAL(timeout()),this,SLOT(rule()));//定时检查伤亡情况
}
//Mwin的构造函数



Mwin::~Mwin()
{
    delete ui;
}
//析构

void Mwin::addmonster(){
    this->myworld.addmonster0(900,300,qrand()%2);//在最右端随机生成不同怪物种类的怪
    this->repaint();
}
void Mwin::monstermove(){
    this->myworld.monstermove0();//调用world里面依次移动函数
    this->repaint();
}

void Mwin::addbullet(){
    this->myworld.addbullet0();//调用myword添加子弹函数
    this->repaint();
}
void Mwin::bulletmove(){
    this->myworld.bulletmove0();//调用myworld子弹依次移动函数
    this->repaint();
}
/*void Mwin::rule(){
    this->myworld.rules();//检查各个物体相遇情况
    this->repaint();
}*/
//以上为五个槽函数



void Mwin::paintEvent(QPaintEvent *event){
    QPainter*paint=new QPainter;//创建指针
    paint->begin(this);//启用画家
    this->myworld.painting(paint);//画出图像
    paint->end();//画完以后，停用画家
    delete paint;
}
//画图事件




void Mwin::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_1:
        this->myworld.getorder(1);
        break;
    case Qt::Key_2:
        this->myworld.getorder(2);
        break;
    case Qt::Key_3:
        this->myworld.getorder(3);
        break;
    case Qt::Key_4:
        this->myworld.getorder(4);
        break;
    case Qt::Key_5:
        this->myworld.getorder(5);
        break;
    case Qt::Key_6:
        this->myworld.getorder(6);
        break;
   }
    this->repaint();
}
//创建键盘事件








