#include "horizontal.h"

horizontal::horizontal()
{

}

void horizontal::eliminate(blank *b[10][10], blank *clicked)
{
    int row=clicked->row;
    for(int i=0;i<10;i++){
        b[row][i]->number=17;//先排除所有特殊狀況
    }
}


horizontal::~horizontal()
{

}

