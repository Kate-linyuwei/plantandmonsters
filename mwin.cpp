#include "mwin.h"
#include "ui_mwin.h"
#include<QMediaPlayer>

int Mwin::prog=0;//设置初始进度为0
Mwin::Mwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mwin)
{
    ui->setupUi(this);

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/Mountains.mp3"));
    player->setVolume(30);
    player->play();//放音乐



    QPixmap pixall(":/picture/model.jpg");
    QPixmap pix=pixall.copy(8*32,6*32,64,64);//截取红色房子
    ui->redplabel->setPixmap(pix);//设置图片
    pix=pixall.copy(10*32,6*32,64,64);//截取蓝色房子
    ui->blueplabel->setPixmap(pix);//设置图片
    pix=pixall.copy(12*32,6*32,64,64);//截取土石塔
    ui->soiltlabel->setPixmap(pix);//设置图片
    pix=pixall.copy(14*32,6*32,64,64);//截取铁塔
    ui->irontlabel->setPixmap(pix);//设置图片
    pix=pixall.copy(12*32,14*32,64,64);//截取雪房
    ui->snowplabel->setPixmap(pix);//设置图片
    pix=pixall.copy(14*32,14*32,64,64);//截取雪塔
    ui->snowtlabel->setPixmap(pix);//设置图片
    //此处在控件上添加图画

    this->changecheck(1);
    this->nowtower=1;//初始化，选择红塔

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
    this->myworld.endcheck();//检查是否失败
    if((this->myworld.getlosecheck()==true)||prog>=100){
        //如果输了或者赢了
        repaint();//最后画一次
        timing->stop();//停止计时
    }
    int golden=this->myworld.getgold();//得到金币数量
    ui->moneybox->setValue(golden);//更新金币数量
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


    if(this->myworld.getlosecheck()==true){
    QFont losefont("宋体",20);
    paint->setPen(Qt::green);//设置绿色
    paint->setFont(losefont);//设置字体
    paint->drawText(132,400,"monster eat your brain!");}
    //如果失败，写出失败提示

    if(prog>=100){
        QFont winfont("宋体",25);
        paint->setPen(Qt::blue);//设置绿色
        paint->setFont(winfont);//设置字体
        paint->drawText(132,400,"you win!congratulations!");
        //如果成功，写出成功提示
    }


    paint->end();//画完以后，停用画家
    delete paint;
}
//画图事件
void Mwin::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_U:
        this->changecheck(1);
        this->nowtower=1;
        break;
    case Qt::Key_I:
        this->changecheck(2);
        this->nowtower=2;
        break;
    case Qt::Key_O:
        this->changecheck(3);
        this->nowtower=3;
        break;
    case Qt::Key_J:
        this->changecheck(4);
        this->nowtower=4;
        break;
    case Qt::Key_K:
        this->changecheck(5);
        this->nowtower=5;
        break;
    case Qt::Key_L:
        this->changecheck(6);
        this->nowtower=6;
        break;
   //字母UIOJKL对应不同塔的类型，进行checkbox的勾选和现今选定类型的变化
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
    connect(timing,SIGNAL(timeout()),this,SLOT(rule()));//定时检查伤亡情况和是否失败
    connect(timing,SIGNAL(timeout()),this,SLOT(changeprogress()));//定时更新进度
}//开始键事件
void Mwin::changeprogress(){
    prog=prog+5;//增加进度
    ui->proBar->setValue(prog);//设置进度
    if(prog>=100){
        QMediaPlayer* win=new QMediaPlayer;
        win->setMedia(QUrl("qrc:/music/win.mp3"));//选择成功声音
        win->setVolume(30);//设置音效
        win->play();//播放
        //成功的声音
    }
}
void Mwin::changecheck(int type){
    ui->redpcheck->setCheckState(Qt::Unchecked);
    ui->bluepcheck->setCheckState(Qt::Unchecked);
    ui->soiltcheck->setCheckState(Qt::Unchecked);
    ui->irontcheck->setCheckState(Qt::Unchecked);
    ui->snowpcheck->setCheckState(Qt::Unchecked);
    ui->snowtcheck->setCheckState(Qt::Unchecked);//先全部设为未选
    switch (type) {
    case 1:
       ui->redpcheck->setCheckState(Qt::Checked);
        break;
    case 2:
       ui->bluepcheck->setCheckState(Qt::Checked);
        break;
    case 3:
       ui->soiltcheck->setCheckState(Qt::Checked);
        break;
    case 4:
       ui->irontcheck->setCheckState(Qt::Checked);
        break;
    case 5:
       ui->snowpcheck->setCheckState(Qt::Checked);
        break;
    case 6:
       ui->snowtcheck->setCheckState(Qt::Checked);
        break;
    }
}


//以下为点击添加塔
void Mwin::on_tower1_clicked()
{
    this->myworld.getorder(nowtower,256,300);//在第1个按钮位置放塔
}

void Mwin::on_tower2_clicked()
{
    this->myworld.getorder(nowtower,320,300);//在第2个按钮位置放塔
}

void Mwin::on_tower3_clicked()
{
    this->myworld.getorder(nowtower,384,300);//在第3个按钮位置放塔
}

void Mwin::on_tower4_clicked()
{
    this->myworld.getorder(nowtower,448,300);//在第4个按钮位置放塔
}

void Mwin::on_tower5_clicked()
{
    this->myworld.getorder(nowtower,256,400);//在第2行第1个按钮位置放塔
}

void Mwin::on_tower6_clicked()
{
    this->myworld.getorder(nowtower,320,400);//在第2行第2个按钮位置放塔
}

void Mwin::on_tower7_clicked()
{
    this->myworld.getorder(nowtower,384,400);//在第2行第3个按钮位置放塔
}


void Mwin::on_tower8_clicked()
{
    this->myworld.getorder(nowtower,448,400);//在第2行第4个按钮位置放塔
}

void Mwin::on_tower9_clicked()
{
    this->myworld.getorder(nowtower,256,500);//在第3行第1个按钮位置放塔
}

void Mwin::on_tower10_clicked()
{
    this->myworld.getorder(nowtower,320,500);//在第3行第2个按钮位置放塔
}

void Mwin::on_tower11_clicked()
{
    this->myworld.getorder(nowtower,384,500);//在第3行第3个按钮位置放塔
}

void Mwin::on_tower12_clicked()
{
    this->myworld.getorder(nowtower,448,500);//在第3行第4个按钮位置放塔
}
