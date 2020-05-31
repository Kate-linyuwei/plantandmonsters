#include "player.h"

defenobj*player::addnewobj(int xx, int yy,int type){
    defenobj* palace=new defenobj; //创建新的塔指针
    switch (type) {
    case 1:
        palace->reset("redpalace",xx,yy);
        break;
    case 2:
        palace->reset("bluepalace",xx,yy);
        break;
    case 3:
        palace->reset("soiltower",xx,yy);
        break;
    case 4:
        palace->reset("irontower",xx,yy);
        break;
    case 5:
        palace->reset("snowpalace",xx,yy);
        break;
    default:
        palace->reset("snowtower",xx,yy);
        break;}
    //根据按键改变指针类型
    return palace;
}
//根据ABCDEF六种按键指令建立塔




