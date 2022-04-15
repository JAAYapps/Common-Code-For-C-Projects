#include "memory.h"

void *memorycopy(void *dst, const void *src, unsigned long long size)
{
    for (unsigned long long i = 0; i < size; i++)
        ((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
    return dst;
}