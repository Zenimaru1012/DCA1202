#include <stdio.h>
#include <stdlib.h>

void soma(int *vet1, int *vet2, int *resultado, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        resultado[i] = vet1[i] + vet2[i];
    }
}

int main()
{
    int n, i;
    int *vet1, *vet2, *resultado;

    printf("Digite a Quantidade de Elementos: ");
    scanf("%d", &n);

    vet1 = malloc(n * sizeof(int));
    vet2 = malloc(n * sizeof(int));

    printf("Digite os Valores do Vetor 1: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &vet1[i]);
    }
-
    printf("Digite os Valores do Vetor 2: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &vet2[i]);
    }

    resultado = malloc(n * sizeof(int));

    soma(vet1, vet2, resultado, n);

    free(vet1);
    free(vet2);

    printf("Vetor Resultado: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ", resultado[i]);
    }

    free(resultado);

    return 0;
}