#include <stdio.h>

int main()
{
    //Seja
    int i=3, j=5;
    int *p, *q;
    p = &i;
    q = &j;

    /*
    Determine:
    a) p == &i;
    b) *p - *q;
    c) **&p;
    d) 3 - *p/(*q) + 7;
    */

    //p == &i
    if(p == &i)
    {
        printf("a) Verdadeiro\n");
    }else printf("a) Falso\n");

    int resposta;

    //*p - *q
    resposta = *p - *q;
    printf("b) %d \n", resposta);

    //**&p
    resposta = **&p;
    printf("c) %d \n", resposta);

    //3 - *p/(*q) + 7
    resposta = 3 - *p/(*q) + 7;
    printf("d) %d \n", resposta);

    return 0;
}