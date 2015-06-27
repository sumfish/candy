#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blank.h"
#include <ctime>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]= new blank(i,j,this);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));//連結訊號
            connect(b[i][j],SIGNAL(movedone()),this,SLOT(zerovanish()));//移動完的訊號會一直保持連結
        }
    }
    gamestart();
}

void MainWindow::setclickpic(blank *b)
{
    switch(b->number){
    case 1:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushred.jpg")));
        b->button->setIconSize(QSize(40,40));//設定圖的大小
        break;
    case 2:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellow.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 3:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushblue.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 4:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreen.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 11:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 21:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 31:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluer.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 41:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 12:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 22:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 32:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluev.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 42:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 13:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 23:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 33:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluebomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 43:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 5:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushstar.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    }
}

void MainWindow::gamestart()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setnumber();//隨機產生圖片
            b[i][j]->setbuttonpic();
            if(j>=2&&b[i][j]->number==b[i][j-1]->number&&b[i][j]->number==b[i][j-2]->number){
                j--;
            }
            if(i>=2&&b[i][j]->number==b[i-1][j]->number&&b[i][j]->number==b[i-2][j]->number){
                j--;//與上方比
            }
        }
}
    isclicked=false;
}

bool MainWindow::judge(int r1, int c1, int r2, int c2)//判斷各種消掉的狀況
{
        judgestar(r1,c1);
        judgestar(r2,c2);
}

bool MainWindow::judgestar(int row, int col)//回傳生成星星的狀況再用produce執行
{
    int return_value;
    bool any_produce=false;
    Destroy*d=new star;//為甚麼呢~~~~~~
    return_value=d->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1:
            d->produce(b,b[row][col],1);
            any_produce=true;
            break;
        case 2:
            d->produce(b,b[row][col],2);
            any_produce=true;
            break;
        case 3:
            d->produce(b,b[row][col],3);
            any_produce=true;
            break;
        case 4:
            d->produce(b,b[row][col],4);
            any_produce=true;
            break;
        }
    }
    delete d;//釋放new出來的空間
    return any_produce;
}

void MainWindow::renewpic()
{
    for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
            b[i][j]->setbuttonpic();
         }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(int row, int column)
{
    if(!isclicked){//第一次點下去
        setclickpic(b[row][column]);//按過的圖片
        isclicked=true;
        record_r=row;//紀錄
        record_c=column;
    }
    else{
        if(record_r==row&&column-1==record_c){
             setclickpic(b[row][column]);
            *b[record_r][record_c]-b[row][column];
             judge(row,column,record_r,record_c);//順序有沒有差??觸發測試有沒有可消的
        }//左
        else if(record_r==row&&column+1==record_c){
             setclickpic(b[row][column]);
            *b[row][column]-b[record_r][record_c];
             judge(row,column,record_r,record_c);
        }//右
        else if(row-1==record_r&&record_c==column){
             setclickpic(b[row][column]);
            *b[record_r][record_c]|b[row][column];
             judge(row,column,record_r,record_c);
        }//上
        else if(row+1==record_r&&record_c==column){
            setclickpic(b[row][column]);
            *b[row][column]|b[record_r][record_c];
            judge(row,column,record_r,record_c);
        }//下
        else{
            setclickpic(b[record_r][record_c]);//再修改點另外的不會變色!!!!!!!!!!!!!
        }
        isclicked=false;
    }
}

void MainWindow::zerovanish()//消掉後移動再消再移動的測試直到填滿為止  和補圈圈!!!
{
    renewpic();
}
