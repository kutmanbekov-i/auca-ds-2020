#ifndef VECINT_H
#define VECINT_H

#include <stddef.h>

struct VecInt
{
    int *p;
    size_t sz;
    size_t cp;
};

void VecInt_createEmpty(struct VecInt *this);
void VecInt_createOfSize(struct VecInt *this, int n, int init_value);
void VecInt_pushBack(struct VecInt *this, int x);
void VecInt_destroy(struct VecInt *this);

#endif