#include <stdio.h>

int main()
{
    int i, j;
    int *p, *q;
    int resposta;

    i = *&j;

    printf("FUNCIONOU \n");

    return 0;
}