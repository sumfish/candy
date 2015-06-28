#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blank.h"
#include <ctime>
#include <stdlib.h>
#include <QDebug>

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
    case 0:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushred.jpg")));
        b->button->setIconSize(QSize(40,40));//設定圖的大小
        break;
    case 1:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellow.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 2:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushblue.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 3:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreen.jpg")));
         b->button->setIconSize(QSize(40,40));
        break;
    case 4:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 5:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 6:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluer.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 7:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenr.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 8:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 9:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 10:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluev.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 11:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenv.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 12:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushredbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 13:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushyellowbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 14:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushbluebomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 15:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushgreenbomb.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    case 16:
        b->button->setIcon(QIcon(QPixmap(":/pic/pushstar.jpg")));
        b->button->setIconSize(QSize(40,40));
        break;
    }
}

void MainWindow::gamestart()
{
    step=10;
    score=0;
    ui->label_4->setText(QString("%1").arg(step));
    ui->label_2->setText(QString("%1").arg(score));
    ui->label_7->setPixmap(QPixmap(":/pic/firststar.jpg"));
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
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            re[i][j]=0;
        }
    }
   // c=0;
}

bool MainWindow::judge(int r1, int c1)//判斷各種消掉的狀況
{
    int ponum=b[r1][c1]->number;//先存要不然炸的時候會修改到
    //qDebug()<<"a";
    record(r1,c1);//消除
    c=c+1;
    //qDebug()<<c;
        if(over!=0){//不一定兩個動的都會消,一定要有消除動作才會變0
             b[r1][c1]->number=17;
          }
        if(lbomb==2){
            b[r1][c1]->number=ponum%4+12;
        }
        switch(indexh){
        case 2:
            b[r1][c1]->number=ponum%4+4;
            break;
        case 3:
            b[r1][c1]->number=16;
            break;
        }
        switch(indexv){
        case 2:
            b[r1][c1]->number=ponum%4+8;
            break;
        case 3:
            b[r1][c1]->number=16;
            break;
        }
        if(over!=0){
            return true;
        }
}


void MainWindow::renewpic()
{
    for(int i=0;i<10;i++){
         for(int j=0;j<10;j++){
            b[i][j]->setbuttonpic();
         }
    }
}

int MainWindow::bomb(int r,int c)
{
       Destroy *d;
       switch(b[r][c]->number/4){
      case 0:
          b[r][c]->number=17;
          score+=5;
          over++;
          break;
      case 1://1~4會引爆
          d=new horizontal;
          d->eliminate(b,b[r][c]);
          score+=20;
          over++;
          delete d;
          break;
      case 2:
          d=new vertical;
          d->eliminate(b,b[r][c]);
          score+=20;
          over++;
          delete d;
          break;
      case 3:
          d=new nineblock;
          d->eliminate(b,b[r][c]);
          score+=30;
          over++;
          delete d;
          break;
      }

}

int MainWindow::record(int r,int c)
{
    int num=b[r][c]->number%4;
    temnum=b[r][c]->number;
    indexv=0;
    indexh=0;
    lbomb=0;
    over=0;
    for(int i=0;i<10;i++){//橫掃
        for(int j=0;j<10;j++){
            if(j<=7&&(b[i][j]->number%4==num)&&(num==b[i][j+1]->number%4)&&(num==b[i][j+2]->number%4)&&b[i][j]->number!=17&&b[i][j+1]->number!=17&&b[i][j+2]->number!=17&&b[i][j]->number!=16&&b[i][j+1]->number!=16&&b[i][j+2]->number!=16){
                indexh++;
                lbomb++;
                bomb(i,j);
                bomb(i,j+1);
                bomb(i,j+2);
                if(b[i][j+3]->number!=16&&b[i][j+3]->number!=17&&j<=6&&(num==b[i][j+3]->number%4)){
                    indexh++;
                    lbomb--;//不會重複紀錄5個星星
                    bomb(i,j+3);
                    if(b[i][j+4]->number!=16&&b[i][j+4]->number!=17&&j<=5&&(num==b[i][j+4]->number%4)){
                        indexh++;
                        bomb(i,j+4);
                   }
                }
            }
        }
    }
    b[r][c]->number=temnum;//把原本的數字覆蓋
    for(int i=0;i<10;i++){//直掃
        for(int j=0;j<10;j++){
            if(j<=7&&(b[j][i]->number%4==num)&&(b[j+1][i]->number%4==num)&&(num==b[j+2][i]->number%4)&&b[j][i]->number!=17&&b[j+1][i]->number!=17&&b[j+2][i]->number!=17&&b[j][i]->number!=16&&b[j+1][i]->number!=16&&b[j+2][i]->number!=16){
                bomb(j,i);
                bomb(j+1,i);
                bomb(j+2,i);
                lbomb++;
                indexv++;
                if(b[j+3][i]->number!=16&&b[j+3][i]->number!=17&&j<=6&&(num==b[j+3][i]->number%4)){
                    indexv++;
                    bomb(j+3,i);
                    lbomb--;
                    if(b[j+4][i]->number!=16&&b[j+4][i]->number!=17&&j<=5&&(num==b[j+4][i]->number%4)){
                        indexv++;
                        bomb(j+4,i);
                    }
                }
            }
        }
    }
}

int MainWindow::drop()
{
    for(int i=0;i<10;i++){
         for(int j=8;j>=0;j--){
             for(int k=j;k<9;k++){
                if(b[k][i]->number!=17&&b[k+1][i]->number==17){
                    b[k+1][i]->number=b[k][i]->number;
                    b[k][i]->number=17;
                }
             }
         }
    }
}

bool MainWindow::trychange(int r,int c)//如果可以換的話會傳true
{
    int num=b[r][c]->number%4;
    if((num==b[r+1][c]->number%4)&&(num==b[r+2][c]->number%4)){
        return true;
    }
    else if((num==b[r-1][c]->number%4)&&(num==b[r-2][c]->number%4)){
        return true;
    }
    else if((num==b[r][c+1]->number%4)&&(num==b[r][c+2]->number%4)){
        return true;
    }
    else if((num==b[r][c-1]->number%4)&&(num==b[r][c-2]->number%4)){
        return true;
    }
    else if((num==b[r+1][c]->number%4)&&(num==b[r-1][c]->number%4)){
        return true;
    }
    else if((num==b[r][c-1]->number%4)&&(num==b[r][c+1]->number%4)){
        return true;
    }
    else{
        return false;
    }
}

int MainWindow::producenewpic()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(b[i][j]->number==17){
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
    }
}

int MainWindow::clearstar(int r, int c)//消除星星
{
      //qDebug()<<"aYY";
    int a=b[r][c]->number%4;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            // qDebug()<<"aEE";
            if((b[i][j]->number!=16)&&(b[i][j]->number!=17)&&(b[i][j]->number%4==a)){
                b[i][j]->number=17;
                score+=50;
                //qDebug()<<"a";
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(int row, int column)
{
    int result1;
    int result2;
    if(!isclicked){//第一次點下去
        setclickpic(b[row][column]);//按過的圖片
        isclicked=true;
        record_r=row;//紀錄
        record_c=column;
       // qDebug()<<"j";
    }
    else{
        if(record_r==row&&column-1==record_c){
             setclickpic(b[row][column]);
            *b[record_r][record_c]-b[row][column];
             result1=trychange(row,column);
             result2=trychange(record_r,record_c);
             if((b[record_r][record_c]->number!=16)&&(b[row][column]->number!=16)&&result1==false&&result2==false){
             *b[record_r][record_c]-b[row][column];
             }
             else{
                step--;
                if(b[row][column]->number==16){
                       // qDebug()<<"T";
                       clearstar(record_r,record_c);
                       b[row][column]->number=17;
                }
                else{
                   // qDebug()<<"T";
                   judge(row,column);
                }

                if(b[record_r][record_c]->number==16){
                    //qDebug()<<"T";
                      clearstar(row,column);
                      b[record_r][record_c]->number=17;
                }
                else{
                   // qDebug()<<"T";
                judge(record_r,record_c);
                }
             }
        }//左
        else if(record_r==row&&column+1==record_c){
             setclickpic(b[row][column]);
             *b[row][column]-b[record_r][record_c];
             result1=trychange(row,column);
             result2=trychange(record_r,record_c);
             if((b[record_r][record_c]->number!=16)&&(b[row][column]->number!=16)&&result1==false&&result2==false){
            *b[row][column]-b[record_r][record_c];
             }
             else{//可換
                 step--;
                 if(b[row][column]->number==16){
                    // qDebug()<<"T";
                        clearstar(record_r,record_c);
                        b[row][column]->number=17;
                 }
                 else{
                   //  qDebug()<<"T";
                    judge(row,column);
                 }

                 if(b[record_r][record_c]->number==16){
                    // qDebug()<<"T";
                       clearstar(row,column);
                      b[record_r][record_c]->number=17;
                 }
                 else{
                    // qDebug()<<"T";
                 judge(record_r,record_c);
                }
             }
        }//右
        else if(row-1==record_r&&record_c==column){
             setclickpic(b[row][column]);
            *b[record_r][record_c]|b[row][column];
             result1=trychange(row,column);
             result2=trychange(record_r,record_c);
             if((b[record_r][record_c]->number!=16)&&(b[row][column]->number!=16)&&result1==false&&result2==false){
             *b[record_r][record_c]|b[row][column];
             }
             else{
                step--;
                if(b[row][column]->number==16){
                   // qDebug()<<"T";
                       clearstar(record_r,record_c);
                       b[row][column]->number=17;
                }
                else{
                   judge(row,column);
                }

                if(b[record_r][record_c]->number==16){
                   // qDebug()<<"T";
                      clearstar(row,column);
                      b[record_r][record_c]->number=17;
                }
                else{
                judge(record_r,record_c);
                }
             }
        }//上
        else if(row+1==record_r&&record_c==column){
            setclickpic(b[row][column]);
            *b[row][column]|b[record_r][record_c];
            result1=trychange(row,column);
            result2=trychange(record_r,record_c);
            if((b[record_r][record_c]->number!=16)&&(b[row][column]->number!=16)&&result1==false&&result2==false){
            *b[row][column]|b[record_r][record_c];
            }
            else{
                step--;
                if(b[row][column]->number==16){
                    //qDebug()<<"T";
                       clearstar(record_r,record_c);
                       b[row][column]->number=17;
                }
                else{
                   judge(row,column);
                }

                if(b[record_r][record_c]->number==16){
                    //qDebug()<<"T";
                      clearstar(row,column);
                      b[record_r][record_c]->number=17;
                }
                else{
                judge(record_r,record_c);
                }
            }
        }//下
        else{
            setclickpic(b[record_r][record_c]);//再修改點另外的不會變色!!!!!!!!!!!!!
            b[record_r][record_c]->setbuttonpic();
        }
        isclicked=false;
    }
}



void MainWindow::zerovanish()//消掉後移動再消再移動的測試直到填滿為止  和補圈圈!!!
{
    ui->label_4->setText(QString("%1").arg(step));
    do{
       //qDebug()<<"k";
       drop();
    }while(lasttest()==true);

    do{
         // qDebug()<<"stop2";
       producenewpic();
    }while(lasttest()==true);
    renewpic();
    ui->label_2->setText(QString("%1").arg(score));
    if(step==0){
          if(score>=1500){
              ui->label_7->setPixmap(QPixmap(":/pic/threestar.jpg"));
          }
          else if(score>=800&&score<1500){
              ui->label_7->setPixmap(QPixmap(":/pic/twostar.jpg"));
          }
          else if(score>=500&&score<800){
              ui->label_7->setPixmap(QPixmap(":/pic/onestar.jpg"));
          }
          else{
              ui->label_7->setPixmap(QPixmap(":/pic/fail.jpg"));
          }
    }
}

bool MainWindow::lasttest()
{
   // qDebug()<<"aaa";
    bool record=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(judge(i,j)){
                record=true;
            }
        }
    }
    //qDebug()<<"stop1";
    if(record==true){
        return true;
    }
    else{
        return false;
    }
}
