#ifndef NINEBLOCK_H
#define NINEBLOCK_H

#include "blank.h"
#include "destroy.h"
#include "horizontal.h"
#include "star.h"
#include "vertical.h"
class nineblock:public Destroy
{
public:
    nineblock();
    virtual void eliminate(blank*b[10][10],blank*clicked);
    virtual ~nineblock();
};

#endif // NINEBLOCK_H
