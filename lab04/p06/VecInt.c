#include "VecInt.h"
#include <stdlib.h>

void VecInt_createEmpty(struct VecInt *this)
{
    this->p = NULL;
    this->sz = 0;
    this->cp = 0;
}

void VecInt_createOfSize(struct VecInt *this, int n, int init_value)
{
    this->p = (int *)malloc(sizeof(int) * n);
    this->sz = n;
    this->cp = n;
    for (size_t i = 0; i < this->sz; ++i)
    {
        this->p[i] = init_value;
    }
}

void VecInt_pushBack(struct VecInt *this, int x)
{
    if (this->sz == this->cp)
    {
        int newCp = this->sz == 0 ? 1 : this->cp * 2;

        int *q = (int *)malloc(sizeof(int) * newCp);
        for (int i = 0; i < this->sz; ++i)
        {
            q[i] = this->p[i];
        }
        free(this->p);
        this->p = q;
        this->cp = newCp;
    }
    this->p[this->sz] = x;
    ++this->sz;
}

void VecInt_destroy(struct VecInt *this)
{
    free(this->p);
}