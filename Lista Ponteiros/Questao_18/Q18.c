#include <stdio.h>
#include <stdlib.h>

void multi_matriz(int **A, int **B, int **C, int a, int b, int c)
{
    int i, j, k, aux = 0;

    for(i=0;i<a;i++)
    {
        for(j=0;j<c;j++)
        {
            C[i][j] = 0;

            for(k=0;k<b;k++)
            {
                aux += A[i][k]*B[k][j];
            }

            C[i][j] = aux;
            aux = 0;
        }
    }
}

int main()
{
    int i, j;
    int **A, **B, **C;
    int a, b, c;

    printf("Digite os valores de a, b, c: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    A = malloc(a * sizeof(int*));
    A[0] = malloc(a * b * sizeof(int));
    for(i=1;i<a;i++)
    {
        A[i] = A[i-1] + b;
    }

    B = malloc(b * sizeof(int*));
    B[0] = malloc(b * c * sizeof(int));
    for(i=1;i<b;i++)
    {
        B[i] = B[i-1] + c;
    }

    C = malloc(a * sizeof(int*));
    C[0] = malloc(a * c * sizeof(int));
    for(i=1;i<a;i++)
    {
        C[i] = C[i-1] + c;
    }

    printf("Digite os Valores de A: \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os Valores de B: \n");
    for(i=0;i<b;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    multi_matriz(A, B, C, a, b, c);

    printf("Valores de C: \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    free(A[0]);
    free(A);
    free(B[0]);
    free(B);
    free(C[0]);
    free(C);

    return 0;
}