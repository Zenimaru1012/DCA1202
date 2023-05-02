#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b ) return -1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a >  *(int*)b ) return 1;
}

int main()
{
    int n, i;
    int *x;

    printf("Digite a Quantidade de Elementos: ");
    scanf("%d", &n);

    x = malloc(n * sizeof(int));

    printf("Digite os Valores do Vetor: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &x[i]);
    }

    qsort(x, n, sizeof(int), compare);

    printf("Vetor Organizado: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    free(x);

    return 0;
}