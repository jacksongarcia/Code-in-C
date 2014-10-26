/**
 * Copyright (c) 05/09/2014 Jackson Garcia Pinheiro Junior

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CLS - Windows, CLEAR - Linux */
const char * LIMPA_TELA =  "cls";

void caracterParaASC(void);
void ASCParaCaracter(void);
void palavraParaASC(void);
void mostrarTabelaASCNaoImprimveis(void);
void mostrarTabelaASCImprimveis(void);
void transformarBinario(int n);

int main(void)
{
    char letra;
    int opcMenu;

    do{
        system(LIMPA_TELA);
        printf("ESCOLHA UMA OPCAO\n"
               "[1]CARACTER PARA DECIMAL/HEXA/BINARIO\n"
               "[2]DECIMAL PARA CARACTER/HEXA/BINARIO\n"
               "[3]PALAVRA PARA DECIMAL/HEXA/BINARII\n"
               "[4]MOSTRAR TABELA ASCII\n");
               
        scanf(" %d", &opcMenu);
    }while((opcMenu < 1) ||(opcMenu > 4));

    switch(opcMenu){
        case 1:
            caracterParaASC();
        break;
        case 2:
            ASCParaCaracter();
        break;
        case 3:
            palavraParaASC();
        break;
        case 4:
            mostrarTabelaASCNaoImprimveis();
            mostrarTabelaASCImprimveis();
        break;
    }

    return EXIT_SUCCESS;
}

/*
    Transforma de caractere para um valores ASC,
    decimal, exadecimal, binario.
*/
void caracterParaASC(){
     char letra;
     int n;

     printf("\nDIGITE UMA LETRA\n"
            "=>");scanf(" %c", &letra);

     system(LIMPA_TELA);
     n = (int)letra;
     printf("LETRA - ASC - HEXA -  BINARIO\n");
     printf("  %c   - %d  -  %x  -  ",letra,letra,letra);transformarBinario(n);
}

/*
    Transforma de ASC para um valores caractere,
    decimal, exadecimal, binario.
*/
void ASCParaCaracter(void){
     int num;
     int n;

     printf("\nDIGITE O NUMERO DECIMAL ASC\n"
            "=>");scanf(" %d", &num);

     system(LIMPA_TELA);
     n = num;
     printf("LETRA - ASC - HEXA -  BINARIO\n");
     printf("  %c   - %d  -  %x  -  ",num,num,num);transformarBinario(n);
}

/*
    Pega um array de caractere e transforma para cada valor,
    decimal, exadecimal, binario.
*/
void palavraParaASC(void){
     char palavra[15];
     int n,i=0;

     printf("\nDIGITE UMA LETRA\n"
            "=>");scanf(" %s", palavra);

     system(LIMPA_TELA);

     printf("\n\nLETRA\n=>");
     for(i = 0; i < strlen(palavra); i++)
        printf("%c ",palavra[i]);

     printf("\n\nASC\n=>");
     for(i = 0; i < strlen(palavra); i++)
        printf("%d ",palavra[i]);

     printf("\n\nHEXA\n=>");
     for(i = 0; i < strlen(palavra); i++)
        printf("%x ",palavra[i]);

     printf("\n\nBINARIO\n=>");
     for(i = 0; i < strlen(palavra); i++){
        n = (int)palavra[i];
        transformarBinario(n);
        printf(" ");
     }
     i++;
}

/*
    Carrega em um array os caractere que não podem ser imprimidos
    por cast, e os imprime formatados na tela.
*/
void mostrarTabelaASCNaoImprimveis(void){
     system(LIMPA_TELA);
     char letra = 0;
     int n,i=0, j;
     const char naoImprimiveis[33][3] = {"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL",
     "BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB",
     "CAN","EM","SUB","ESC","FS","GS","RS","US","DEL"};

     printf("\n\n\tCARACTERES QUE NAO PODEM SER IMPRIMIDO, SERA MOSTRADO SUA ABREVIACAO\n\n");
     while(i < 127){
         n = (int)letra;
         printf("\t\t\t BINARIO | DECIMAL | HEXA | ABREVIACAO\n");
         printf("\t\t\t");transformarBinario(n);printf(" |    %d   |    %x  |    ",letra,letra);

         for(j = 0; j < 3; j++){
             (i == 126) ? printf("%c",naoImprimiveis[32][j]) : printf("%c",naoImprimiveis[i][j]);
         }

         letra++;
         i++;
         if(i == 32)i = 126;
         printf("\n\n");
     }
}

/*
    Mostra toda a tabela ASC, com os seu respectivos valores.
*/
void mostrarTabelaASCImprimveis(void){
     char enter;
     char letra = 32;
     int n,i=32;

     printf("\n\n\t\t\tCARACTERES QUE PODEM SER IMPRIMIDO\n\n");
     printf("PRESSIONE QUALQUER BOTAO PARA CONTINUAR...");scanf(" %c", &enter);
     system(LIMPA_TELA);
     printf("\n\n\t\t\tCARACTERES QUE PODEM SER IMPRIMIDO\n\n");
     while(i <= 123){
         n = (int)letra;
         printf("\t\t\t BINARIO  |  DECIMAL  |  HEXA  |  LETRA\n");
         printf("\t\t\t");transformarBinario(n);printf("  |     %d   |    %x  |    %c",letra,letra,letra);

         letra++;
         i++;
         printf("\n\n");
     }
}

/*
    Faz a conversao de de um numero para binário.
*/

void transformarBinario(int n){
    int binario[8];
    int i = 7, resto = 0;

    while(n > 0){
        resto = n % 2;
        if(resto == 0)
            binario[i] = 0;
        else
            binario[i] = 1;
        i--;
        n = n / 2;
    }
    while(i >= 0){
        binario[i] = 0;
        i--;
    }
    for(i = 0; i < 8; i++)
        printf("%d", binario[i]);
}
