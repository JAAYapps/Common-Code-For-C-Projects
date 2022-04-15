#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

void *AssignMemory(UINT64 typeSize, UINT64 ElementSize);

void FreeMemory(void *element);

void *AssignAndInitMemory(UINT64 typeSize, UINT64 ElementSize);

void *ResizeMemory(void *element, UINT64 originalSize, UINT64 typeSize, UINT64 ElementSize);

void *memorycopy(void *dst, const void *src, unsigned long long size);

#endif
