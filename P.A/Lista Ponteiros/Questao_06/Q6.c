/*
    Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões referenciam o valor do terceiro elemento do vetor?
        a) *(pulo + 2);
        b) *(pulo + 4);
        c) pulo + 4;
        d) pulo + 2;

    Seria a expressão "a"
*/

//Prova:

#include <stdio.h>

int main()
{
    int pulo[5] = {1, 2, 3, 4, 5};

    printf("%d", *(pulo + 2));

    return 0;
}