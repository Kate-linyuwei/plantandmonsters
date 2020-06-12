#include "mwin.h"
#include "ui_mwin.h"
#include<QMediaPlayer>


Mwin::Mwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mwin)
{
    ui->setupUi(this);

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/Mountains.mp3"));
    player->setVolume(30);
    player->play();//放音乐

   /* myworld.originset();//设置初始塔怪
    timing=new QTimer(this);
    timing->setInterval(2000);//设置间隔1000ms
    timing->start();//开始计时
    connect(timing,SIGNAL(timeout()),this,SLOT(addmonster()));
    connect(timing,SIGNAL(timeout()),this,SLOT(monstermove()));
    connect(timing,SIGNAL(timeout()),this,SLOT(addbullet()));
    connect(timing,SIGNAL(timeout()),this,SLOT(bulletmove()));//将定时发生的移动和产生创建联系
    connect(timing,SIGNAL(timeout()),this,SLOT(rule()));//定时检查伤亡情况
*/
}
//Mwin的构造函数



Mwin::~Mwin()
{
    delete ui;
}
//析构

void Mwin::addmonster(){
    int y=300+(qrand()%3)*100;//随机哪一条线产生怪物
    this->myworld.addmonster0(704,y,qrand()%2);//在最右端随机生成不同怪物种类的怪
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
void Mwin::rule(){
    this->myworld.rules();//检查各个物体相遇情况
    this->repaint();
}
//以上为五个槽函数



void Mwin::paintEvent(QPaintEvent *event){
    QPainter*paint=new QPainter;//创建指针
    paint->begin(this);//启用画家
    QImage background;
    background.load(":/picture/grass.jpg");//引入背景画像
    paint->drawImage(132,300,background);//画出背景
    this->myworld.painting(paint);//画出图像



    QFont font("宋体",10);//设置字体
    QApplication::setFont(font); //将字体设为QApplication默认字体
    paint->drawText(800,320,tr("welcome to this tower game!"));
    paint->drawText(800,370,tr("you can use keyboard to play"));
    paint->drawText(800,420,tr("push U/I/O/J/K/L can add new tower"));
    paint->drawText(800,470,tr("push W and S key can change"));
    paint->drawText(800,520,tr("the roll you add tower to"));
    paint->drawText(800,570,tr("please enjoy your game,thanks!"));
    paint->drawText(132,680,tr("click the buttom to get start"));
    //添加文字说明

    paint->end();//画完以后，停用画家
    delete paint;
}
//画图事件
void Mwin::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_U:
        this->myworld.getorder(1);
        break;
    case Qt::Key_I:
        this->myworld.getorder(2);
        break;
    case Qt::Key_O:
        this->myworld.getorder(3);
        break;
    case Qt::Key_J:
        this->myworld.getorder(4);
        break;
    case Qt::Key_K:
        this->myworld.getorder(5);
        break;
    case Qt::Key_L:
        this->myworld.getorder(6);
        break;
   //字母UIOJKL对应不同塔的类型，进行添加
    case Qt::Key_W:
        this->myworld.changeline(0);
        break;
    case Qt::Key_S:
        this->myworld.changeline(1);
        break;
   //上键和下键对应行的变化，初始为第一行添加塔
    }
    this->repaint();
}
//创建键盘事件
void Mwin::on_beginbottom_clicked()
{
    myworld.originset();//设置初始塔怪
    timing=new QTimer(this);
    timing->setInterval(2000);//设置间隔1000ms
    timing->start();//开始计时
    connect(timing,SIGNAL(timeout()),this,SLOT(addmonster()));
    connect(timing,SIGNAL(timeout()),this,SLOT(monstermove()));
    connect(timing,SIGNAL(timeout()),this,SLOT(addbullet()));
    connect(timing,SIGNAL(timeout()),this,SLOT(bulletmove()));//将定时发生的移动和产生创建联系
    connect(timing,SIGNAL(timeout()),this,SLOT(rule()));//定时检查伤亡情况
}//开始键事件
