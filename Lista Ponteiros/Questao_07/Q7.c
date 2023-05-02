#include <stdio.h>

int main()
{
    int mat[4], *p, x;

    p = (*mat)++;

    printf("Funcionou \n");

    return 0;
}