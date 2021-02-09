#include <stdio.h>
#include <stdlib.h>

main () 
{
    int i = 0;
    int Array[10];

    for(i = 0; i < 10; i++) 
    {
        Array[i] = rand() % 10;
        printf("%d ", Array[i]);
    }
}