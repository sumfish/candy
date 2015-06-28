 #include "star.h"

star::star()
{

}

void star::produce(blank *b[10][10], blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->column;
    int num=clicked->number;
    int five[5]={0};
    switch(mode){
        case 1://中間正常產生星星(垂直)
            clicked->number=5;
            if(col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
                b[row][col-2]->number=0;//左邊可以產生炸彈
                b[row][col-1]->number=0;
            }
            if(col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
                    b[row][col+1]->number=0;//右
                    b[row][col+2]->number=0;
            }
            if(b[row-2][col]->number/10!=0){//測其他點有沒有特殊可以引爆的東西例如炸彈(若都正常的話就會是初始的0)
                five[0]=b[row-2][col]->number%10;
            }
            if(b[row-1][col]->number/10!=0){
                five[1]=b[row-1][col]->number%10;
            }
                five[2]=b[row][col]->number;

            if(b[row+1][col]->number/10!=0){
                five[3]=b[row+1][col]->number%10;
            }
            if(b[row+2][col]->number/10!=0){
                five[4]=b[row+2][col]->number%10;
            }
            for(int i=0;i<5;i++){//做引爆的動作
                Destroy *d;
                switch(five[i]){
                case 0:
                    b[row-2+i][col]->number=0;//存成0
                    break;
                case 1://1~4會引爆
                    d=new vertical;
                    d->eliminate(b,b[row-2+i][col]);
                    delete d;
                    break;
                case 2:
                    d=new horizontal;
                    d->eliminate(b,b[row-2+i][col]);
                    delete d;
                    break;
                case 3:
                    d=new nineblock;
                    d->eliminate(b,b[row-2+i][col]);
                    delete d;
                    break;
                }
            }
        break;
       case 2:
        clicked->number=5;//水平的中間產生星星
        if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-2][col]->number=0;//左邊可以產生炸彈
            b[row-1][col]->number=0;
        }
        if(row<=7&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                b[row+1][col]->number=0;//右
                b[row+2][col]->number=0;
        }
        if(b[row][col-2]->number/10!=0){//測其他點有沒有特殊可以引爆的東西例如炸彈(若都正常的話就會是初始的0)
            five[0]=b[row][col-2]->number%10;
        }
        if(b[row][col-1]->number/10!=0){
            five[1]=b[row][col-1]->number%10;
        }
            five[2]=b[row][col]->number;

        if(b[row][col+1]->number/10!=0){
            five[3]=b[row][col+1]->number%10;
        }
        if(b[row][col+2]->number/10!=0){
            five[4]=b[row][col+2]->number%10;
        }
        for(int i=0;i<5;i++){//做引爆的動作
            Destroy *d;
            switch(five[i]){
            case 0:
                b[row][col-2+i]->number=0;//存成0
                break;
            case 1://1~4會引爆
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
     case 3:
        num/=10;//看中間的顏色(第三種是特殊的)
        clicked->number=5;
        if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-2][col]->number=0;//左邊可以產生炸彈
            b[row-1][col]->number=0;
        }
        if(row<=7&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                b[row+1][col]->number=0;//右
                b[row+2][col]->number=0;
        }
        if(b[row][col-2]->number/10!=0){//測其他點有沒有特殊可以引爆的東西例如炸彈(若都正常的話就會是初始的0)
            five[0]=b[row][col-2]->number%10;
        }
        if(b[row][col-1]->number/10!=0){
            five[1]=b[row][col-1]->number%10;
        }
        five[2]=b[row][col]->number%10; //已經是特殊狀況 是炸彈直接存

        if(b[row][col+1]->number/10!=0){
            five[3]=b[row][col+1]->number%10;
        }
        if(b[row][col+2]->number/10!=0){
            five[4]=b[row][col+2]->number%10;
        }
        for(int i=0;i<5;i++){//做引爆的動作
            Destroy *d;
            switch(five[i]){
            case 0:
                b[row][col-2+i]->number=0;//存成0
                break;
            case 1://1~4會引爆
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    case 4:
        num/=10;//看中間的顏色(第三種是特殊的)
        clicked->number=5;//水平的中間產生星星
        if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-2][col]->number=0;//左邊可以產生炸彈
            b[row-1][col]->number=0;
        }
        if(row<=7&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                b[row+1][col]->number=0;//右
                b[row+2][col]->number=0;
        }
        if(b[row][col-2]->number/10!=0){//測其他點有沒有特殊可以引爆的東西例如炸彈(若都正常的話就會是初始的0)
            five[0]=b[row][col-2]->number%10;
        }
        if(b[row][col-1]->number/10!=0){
            five[1]=b[row][col-1]->number%10;
        }

            five[2]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0){
            five[3]=b[row][col+1]->number%10;
        }
        if(b[row][col+2]->number/10!=0){
            five[4]=b[row][col+2]->number%10;
        }
        for(int i=0;i<5;i++){//做引爆的動作
            Destroy *d;
            switch(five[i]){
            case 0:
                b[row][col-2+i]->number=0;//存成0
                break;
            case 1://1~4會引爆
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new nineblock;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
}
}

void star::eliminate(blank *b[10][10], blank *clicked)
{

}

int star::condition(blank *b[10][10], blank *clicked)
{
    int row=clicked->row;
    int col=clicked->column;
    int num=clicked->number;
    if(/*num!=0&&*/num!=16){//排除5個星星和空掉的狀況
       if(num/4==0){
            if(row>=2&&row<=7&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
           //垂直的正常生成 在邊界數量不夠時不用比較
           return 1;
            }
            if(col>=2&&col<=7&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
           //水平的正常生成
           return 2;
            }
       }
       else{
           num/=10;//得到顏色
           if(row>=2&&row<=7&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
               return 3;
           }
           if(col>=2&&col<=7&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
               return 4;
           }
       }
    }
    return 0;//都不是的情況
}

star::~star()
{

}



