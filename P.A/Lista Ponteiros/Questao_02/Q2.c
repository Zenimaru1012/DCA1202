#include <stdio.h>

int main()
{
    /*
        Mostre o que será impresso por programa supondo que i ocupa o endereço 4094 na memória.
    */

    int i=5, *p;
    p = &i;
    printf("%x %d %d %d %d", p, *p+2, **&p, 3**p, **&p+4);

    /*
        Caso o endereço de i seja 4094, seria impresso "4094 7 5 15 9", 
        pois apenas o local do endereço de i seria diferente, enquanto que seu conteúdo continuaria o mesmo, 
        dessa forma, nao afetaria as operações seguintes.
    */

     return 0;
}