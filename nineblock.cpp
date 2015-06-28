#include "nineblock.h"



nineblock::nineblock()
{

}



void nineblock::eliminate(blank *b[10][10], blank *clicked)
{
 int row=clicked->row;
 int col=clicked->column;
 clicked->number=17;//將中間那格歸零
 //b[row][col]->number=17;
 if(row>=1&&col>=1){//邊界問題8種格子(還沒寫完!!!!)
     b[row-1][col-1]->number=17;
 }
 if(row>=1){
     b[row-1][col]->number=17;
 }
 if(row>=1&&col<=8){
     b[row-1][col+1]->number=17;
 }
 if(col>=1){
      b[row][col-1]->number=17;
 }
 if(col<=8){
      b[row][col+1]->number=17;
 }
 if(row<=8&&col>=1){
     b[row+1][col-1]->number=17;
 }
 if(row<=8){
      b[row+1][col]->number=17;
 }
 if(row<=8&&col<=8){
     b[row+1][col+1]->number=17;
 }
}


nineblock::~nineblock()
{

}

