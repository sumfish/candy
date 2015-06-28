#ifndef VERTICAL_H
#define VERTICAL_H

#include "blank.h"
#include "destroy.h"
#include "horizontal.h"
#include "nineblock.h"
#include "star.h"
class vertical:public Destroy
{
public:
    vertical();
    virtual void eliminate(blank*b[10][10],blank*clicked);
    virtual ~vertical();
};

#endif // VERTICAL_H
