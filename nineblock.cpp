#include "nineblock.h"



nineblock::nineblock()
{

}

void nineblock::produce(blank *b[10][10], blank *clicked, int mode)
{

}

void nineblock::eliminate(blank *b[10][10], blank *clicked)
{
 int row=clicked->row;
 int col=clicked->column;
 clicked->number=0;//將中間那格歸零
 if(row>=1&&col>=1){//邊界問題8種格子(還沒寫完!!!!)
     b[row-1][col-1]->number=0;
 }
 if(row>=1){
     b[row-1][col]->number=0;
 }
 if(row>=1&&col<=8){
     b[row-1][col+1]->number=0;
 }
 if(row>=1&&col<=8){
     b[row+1][col-1]->number=0;
 }
 if(col<=8){
       b[row+1][col]->number=0;
 }
 if(row<=8&&col<=8){
     b[row+1][col+1]->number=0;
 }

}

int nineblock::condition(blank *b[10][10], blank *clicked)
{

}

nineblock::~nineblock()
{

}

