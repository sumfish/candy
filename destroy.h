#ifndef DESTROY_H
#define DESTROY_H

#include "blank.h"
class Destroy
{
public:
    Destroy();
    virtual void produce(blank*b[10][10],blank*clicked,int mode)=0;//virtual多型 =0pure 生成
    virtual void eliminate(blank*b[10][10],blank*clicked)=0;
    virtual int condition(blank*b[10][10],blank*clicked)=0;
    virtual ~Destroy();
};


#endif // DESTROY_H
