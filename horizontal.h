#ifndef HORIZONTAL_H
#define HORIZONTAL_H

#include "blank.h"
#include "destroy.h"
#include "star.h"
#include "nineblock.h"
#include "vertical.h"
class horizontal:public Destroy
{
public:
    horizontal();
    virtual void produce(blank*b[10][10],blank*clicked,int mode);
    virtual void eliminate(blank*b[10][10],blank*clicked);
    virtual int condition(blank*b[10][10],blank*clicked);
    virtual ~horizontal();
};

#endif // HORIZONTAL_H
