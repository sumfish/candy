#include "horizontal.h"

horizontal::horizontal()
{

}

void horizontal::produce(blank *b[10][10], blank *clicked, int mode)
{

}

void horizontal::eliminate(blank *b[10][10], blank *clicked)
{
    int row=clicked->row;
    for(int i=0;i<10;i++){
        b[row][i]->number=17;//先排除所有特殊狀況
    }
}

int horizontal::condition(blank *b[10][10], blank *clicked)
{

}

horizontal::~horizontal()
{

}

