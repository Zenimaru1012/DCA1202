/*
    Respostas questão 9:
    Supondo que x esteja armazenado no endereço de memória 4092, então teremos um pulo de 1 byte para o tipo CHAR, 4 bytes para o tipo INT, 
    4 bytes para o tipo FLOAT e 8 bytes para o tipo double, tendo assim os seguintes endereços:

    ◦ x for declarado como char?
        x+1 = 4093
        x+2 = 4094
        x+3 = 4095

        Pulos de 1 byte

    ◦ x for declarado como int?
        x+1 = 4094
        x+2 = 4096
        x+3 = 4098

        Pulos de 4 bytes

    ◦ x for declarado como float?
        x+1 = 4096
        x+2 = 4100
        x+3 = 4104

        Pulos de 4 bytes
        
    ◦ x for declarado como double?
        x+1 = 4100
        x+2 = 4108
        x+3 = 4116

        Pulos de 8 bytes
*/

#include <stdio.h>

int main()
{
    char a[4];
    int b[4];
    float c[4];
    double d[4];
    int i, x, y;

    printf("Tipo CHAR:\n");
    for(i=0;i<4;i++)
    {
        printf("x + %d = %d \n", i, &a[i]);
    }
    x = &a[0];
    y = &a[1];
    printf("Pulos de %d bytes\n", y - x);

    printf("Tipo INT:\n");
    for(i=0;i<4;i++)
    {
        printf("x + %d = %d \n", i, &b[i]);
    }
    x = &b[0];
    y = &b[1];
    printf("Pulos de %d bytes\n", y - x);

    printf("Tipo FLOAT:\n");
    for(i=0;i<4;i++)
    {
        printf("x + %d = %d \n", i, &c[i]);
    }
    x = &c[0];
    y = &c[1];
    printf("Pulos de %d bytes\n", y - x);

    printf("Tipo DOUBLE:\n");
    for(i=0;i<4;i++)
    {
        printf("x + %d = %d \n", i, &d[i]);
    }
    x = &d[0];
    y = &d[1];
    printf("Pulos de %d bytes\n", y - x);

    return 0;
}