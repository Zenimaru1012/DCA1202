/*
	12. O que é um ponteiro para uma função? Pesquise na Internet referências sobre o assunto e
	escreva um pequeno programa exemplificando o uso deste recurso.

	Em C, o identificador de uma função é visto como uma referência/endereço para uma área de memória onde se encontram instruções
	que caracterizam a função. Por isso, o identificador pode ser visto como um ponteiro e assim, funções podem ser acessadas usando ponteiros, de forma similar às variáveis.
*/

#include <stdio.h>

void soma(int a, int b)
{
	printf("Soma = %d\n", a+b);
}

void sub(int a, int b)
{
	printf("Subtração = %d\n", a-b);
}

int main()
{	
	//Declaração de um array de ponteiros para as funções soma e sub
	void (*pf_array[]) (int, int) = {soma, sub};
	int a = 2, b = 5;

	//Chama a função soma, através do array de ponteiros pf_array
	(*pf_array[0]) (a, b);

	//Chama a função sub, através do array de ponteiros pf_array
	(*pf_array[1]) (a, b);

	return 0;
}