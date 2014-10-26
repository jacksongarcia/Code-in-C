/**
 * Calculadora para opera��es simples de
 * soma, subtra��o, divis�o, multiplica��o e potencia.
 * Possivel passar a express�o por argumento com essa sintaxe
 * 2 (+) 2, ou inserir a express�o pela interface de usuario
 * 2 + 2, a entrada pelo parametro s� aceita express�es de
 * potencia 2 \\* 2, mas pela interface de usario funcionalidade
 * sem problema 2 ^ 2.
 * C�digo totalmente livre para uso, licensa MIT.
 * @author Jackson Garcia Pinheiro Junior - jacksongarciajr@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int num1, num2;
    char op;

    if(argc <= 1) {
        puts ("ESCREVA A EXPRESSAO. EXE: 2 + 2");
        scanf(" %d %c %d", &num1, &op, &num2);

    } else if (argc == 4) {
        num1 = (int)argv[1][0] - 48;
        num2 = (int)argv[3][0] - 48;
        op   = (char)argv[2][1];
        if (op == '\\') op = (char)argv[2][2];

    } else {
        puts ("PARAMETROS INVALIDOS. EXE: 2 (+) 2");
        exit (1);
    }

    if (op == '^') {
            int prov = num1;
            while (num2 > 1) {num1 *= prov; num2--;}
            printf("\nPOTENCIA: %d\n", num1);
    }
    else if (op == '+') printf ("\nSOMA: %d\n", num1 + num2);
    else if (op == '-') printf ("\nSUBTRACAO: %d\n", num1 - num2);
    else if (op == '*') printf ("\nMULTIPLICAO: %d\n", num1 * num2);
    else if ((op == '/') && (num2 > 0)) printf ("\nDIVISAO: %d\n", num1 / num2);
    else if (num2 == 0) printf ("\nDIVISAO POR ZERO ERROR\n");
    else printf ("\nOPERADOR NAO RECONHECIDO: ERROR \"%c\"\n", op);
}
