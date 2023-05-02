#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare (const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b ) return -1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a >  *(int*)b ) return 1;
}

int main()
{
    int n, i;
    double time_spent = 0.0;
    int *x;

    printf("Digite a Quantidade de Elementos: ");
    scanf("%d", &n);

    x = malloc(n * sizeof(int));

    printf("Digite os Valores do Vetor: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &x[i]);
    }

    time_t begin = clock();

    qsort(x, n, sizeof(int), compare);

    time_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Vetor Organizado: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    printf("Tempo decorrido: %f \n", time_spent);

    free(x);

    return 0;
}