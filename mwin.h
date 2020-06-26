#ifndef MWIN_H
#define MWIN_H
#include"world.h"
#include"player.h"
#include"defenobj.h"
#include"monster.h"
#include"bullet.h"
#include"icon.h"
#include<QImage>
#include<string.h>
#include<QMediaPlayer>
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>

#include <QMainWindow>

namespace Ui {
class Mwin;
}

class Mwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mwin(QWidget *parent = 0);
    ~Mwin();
    void paintEvent(QPaintEvent *event);//画图，画出界面
    void keyPressEvent(QKeyEvent *event);//建立按键联系
protected slots:
    void addmonster();
    void monstermove();
    void addbullet();
    void bulletmove();
    //创建四个槽函数，生成怪物和子弹，怪物移动和子弹移动
    void rule();//检查是否子弹和怪，塔相遇
    void changecheck(int type);//更改选中塔的函数

private slots:
    void on_beginbottom_clicked();
    void changeprogress();//更改进度的槽函数
    void on_tower1_clicked();
    void on_tower2_clicked();
    void on_tower3_clicked();
    void on_tower4_clicked();
    void on_tower5_clicked();
    void on_tower6_clicked();
    void on_tower7_clicked();
    void on_tower8_clicked();
    void on_tower9_clicked();
    void on_tower10_clicked();
    void on_tower11_clicked();
    void on_tower12_clicked();
private:
    Ui::Mwin *ui;
    world myworld;//创建世界
    QTimer *timing;//计时器
    static int prog;//进度值，到100就赢
    int nowtower;//当下选中的塔的类型
};

#endif // MWIN_H
