#ifndef COMMON_H
#define COMMON_H

#define true 1
#define false 0
#ifndef NULL
#define NULL (void *)0
#endif

#define DECIMAL 10
#define HEX 16

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;

typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long long INT64;

typedef UINT8 BOOL;

unsigned char *OpenAndWriteFileToMemory(char *fileName, UINT64 *size);

void Print(char *str);

#endif