#include "vertical.h"

vertical::vertical()
{

}

void vertical::produce(blank *b[10][10], blank *clicked, int mode)
{

}

void vertical::eliminate(blank *b[10][10], blank *clicked)
{
    int col=clicked->column;
    for(int i=0;i<10;i++){
        b[i][col]->number=17;//先排除所有特殊狀況
    }

}

int vertical::condition(blank *b[10][10], blank *clicked)
{

}

vertical::~vertical()
{

}

