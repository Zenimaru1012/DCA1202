/*
    O programa irá imprimir os valores que estão contidos em "vet" através de um loop.
*/

//Prova:

#include <stdio.h>

int main()
{
    int vet[] = {4, 9, 13};
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d ", *(vet + i));
    }
}