#ifndef DESTROY_H
#define DESTROY_H

#include "blank.h"
class Destroy
{
public:
    Destroy();
    virtual void eliminate(blank*b[10][10],blank*clicked)=0;
    virtual ~Destroy();
};


#endif // DESTROY_H
