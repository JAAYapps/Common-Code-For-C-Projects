#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        UINT64 size = 0;
        printf("The argument supplied is %s\n", argv[1]);
        unsigned char *src = OpenAndWriteFileToMemory(argv[1], &size);
        unsigned char *csrc = src;
        while (*csrc != '\0')
        {
            printf(" %c", *csrc);
            csrc++;
        }
        printf("\n");

        printf("\nFreeing Memory of size %lld", size);
        FreeMemory(src);
        printf("\nDone!!!");
    }
    return 0;
}

void *AssignAndInitMemory(UINT64 typeSize, UINT64 ElementSize)
{
    return calloc(ElementSize, typeSize);
}

void *AssignMemory(UINT64 typeSize, UINT64 ElementSize)
{
    return malloc(ElementSize * typeSize);
}

void *ResizeMemory(void *element, UINT64 originalSize, UINT64 typeSize, UINT64 ElementSize)
{
    return realloc(element, ElementSize * typeSize);
}

void FreeMemory(void *element)
{
    free(element);
}

unsigned char *OpenAndWriteFileToMemory(char *fileName, UINT64 *size)
{
    FILE *file = fopen((const char *)fileName, "rb");

    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        long sz = ftell(file);
        char n[12];
        itoa(sz, n, DECIMAL);
        n[11] = '\0';
        Print("\r\nSize of file is ");
        Print(n);
        Print("\r\n");
        fseek(file, 0, SEEK_SET);
        unsigned char *byte = AssignAndInitMemory(sizeof(char), sz + 1);
        for (long i = 0; i < sz; i++)
            byte[i] = (char)fgetc(file);
        byte[sz] = '\0';
        fclose(file);
        *size = sz;
        return byte;
    }
    else
    {
        printf("File %s encountered an error.\n", fileName);
    }
    return NULL;
}

void Print(char *str)
{
#ifdef PRINT
    printf((const char *)str);
#endif
}