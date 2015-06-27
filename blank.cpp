#include "blank.h"

blank::blank(int R,int C,QWidget *parent):row(R),column(C),QObject(parent)
{
    button = new QPushButton (parent);
    button ->setGeometry(column*50,row*50,50,50);
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
    shift=1;
    time=new QTimer();
}

void blank::setnumber()
{
    number=rand()%4+1; //定義圖的數字
}

void blank::setbuttonpic()
{
    switch(number){
    case 1:
        button->setIcon(QIcon(QPixmap(":/pic/red.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/pic/yellow.jpg")));
         button->setIconSize(QSize(40,40));
        break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/pic/blue.jpg")));
         button->setIconSize(QSize(40,40));
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/pic/green.jpg")));
         button->setIconSize(QSize(40,40));
        break;
    case 11:
        button->setIcon(QIcon(QPixmap(":/pic/redr.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 21:
        button->setIcon(QIcon(QPixmap(":/pic/yellowr.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 31:
        button->setIcon(QIcon(QPixmap(":/pic/bluer.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 41:
        button->setIcon(QIcon(QPixmap(":/pic/greenr.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/pic/redv.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/pic/yellowv.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/pic/bluev.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 42:
        button->setIcon(QIcon(QPixmap(":/pic/greenv.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/pic/redbomb.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/pic/yellowbomb.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/pic/bluebomb.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 43:
        button->setIcon(QIcon(QPixmap(":/pic/greenbomb.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/pic/star.jpg")));
        button->setIconSize(QSize(40,40));
        break;
    default:
        button->setIcon(QIcon(QPixmap(" ")));//圖形空掉的狀態
        button->setIconSize(QSize(40,40));
        break;
    }
}

void blank::operator-(blank*b){
    int tmp_num=b->number;//主人是左邊格子,數字交換
    b->number=number;
    number=tmp_num;
    connect(time,SIGNAL(timeout()),this,SLOT(moveright()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveleft()));
    time->start(100);//每100豪秒
    b->time->start(100);
}

void blank::operator|(blank *b)
{
    int tmp_num=b->number;
    b->number=number;
    number=tmp_num;
    connect(time,SIGNAL(timeout()),this,SLOT(moveup()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(movedown()));
    time->start(100);//每100豪秒
    b->time->start(100);
}

void blank::click(){//發出按的訊息
    emit Click(row,column);
}

void blank::moveleft()
{
    button->setGeometry(column*50-shift*10,row*50,50,50);
    shift++;\
    if(shift==5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveleft()));
        button->setGeometry(column*50,row*50,50,50);//實際的鈕是不會動的所以要回來
        setbuttonpic();
        emit movedone();
    }
}

void blank::moveright()
{
    button->setGeometry(column*50+shift*10,row*50,50,50);
    shift++;\
    if(shift==5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveright()));
        button->setGeometry(column*50,row*50,50,50);//實際的鈕是不會動的所以要回來
        setbuttonpic();
        emit movedone();
    }
}

void blank::movedown()
{
    button->setGeometry(column*50,row*50-shift*10,50,50);//給定移動到目的地的位置
    shift++;//慢慢移動
    if(shift==5){//移動完才會進去
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(movedown()));
        button->setGeometry(column*50,row*50,50,50);//實際的鈕是不會動的所以要回來
        setbuttonpic();
        emit movedone();//移動完圖片會發出訊號才可以刷新圖片
    }
}

void blank::moveup()
{
    button->setGeometry(column*50,row*50+shift*10,50,50);
    shift++;\
    if(shift==5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveup()));
        button->setGeometry(column*50,row*50,50,50);//實際的鈕是不會動的所以要回來
        setbuttonpic();
        emit movedone();
    }
}

