#include "vertical.h"

vertical::vertical()
{

}

void vertical::eliminate(blank *b[10][10], blank *clicked)
{
    int col=clicked->column;
    for(int i=0;i<10;i++){
        b[i][col]->number=17;//先排除所有特殊狀況
    }

}

vertical::~vertical()
{

}

