#ifndef STAR_H
#define STAR_H

#include "blank.h"
#include "destroy.h"
#include "horizontal.h"
#include "nineblock.h"
#include "vertical.h"
class star:public Destroy //繼承
{
public:
    star();
    virtual void eliminate(blank*b[10][10],blank*clicked);
    virtual ~star();
};

#endif // STAR_H
