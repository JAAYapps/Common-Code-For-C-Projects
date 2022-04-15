gcc -Wall -Werror -m64 -ffreestanding -DPRINT -c example.c -o example.o
gcc -Wall -Werror -m64 -ffreestanding -DPRINT -c memory.c -o memory.o

gcc -Wall -Werror -m64 example.o memory.o -o example.exe
.\example.exe example.txt

del *.o

pause