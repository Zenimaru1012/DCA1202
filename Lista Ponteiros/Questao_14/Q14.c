//Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>

//Função de comparação, retorna um valor que inteiro que será utilizado na função qsort
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    //Declaração de variável n, que indica a quantidade de elementos, e variável i, que serve como index
    int n, i;
    //Declaração de um ponteiro para float x
    float *x;

    //Recebe um valor inteiro enviado pelo usuário e salva em n
    printf("Digite a Quantidade de Elementos: ");
    scanf("%d", &n);

    //Utiliza alocação dinâmica em x, para reservar n espaços de tamanho float.
    x = malloc(n * sizeof(float));

    //Coleta dos valores iniciais do vetor
    printf("Digite os Valores do Vetor: \n");
    for(i=0;i<n;i++)
    {
        scanf("%f", &x[i]);
    }

    //Utiliza a função qsort para organizar o vetor
    qsort(x, n, sizeof(float), compare);

    //Imprime no terminal o novo vetor organizado
    printf("Vetor Organizado: \n");
    for(i=0;i<n;i++)
    {
        printf("%.2f ", x[i]);
    }

    //libera a memória reservada pelo malloc
    free(x);

    return 0;
}