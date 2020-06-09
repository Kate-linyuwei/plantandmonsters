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


private slots:
    void on_beginbottom_clicked();

private:
    Ui::Mwin *ui;
    world myworld;//创建世界
    QTimer *timing;//计时器

};

#endif // MWIN_H
