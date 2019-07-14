#include <stdio.h>
#include "funcoes.h"

void ler_matriz(matriz *, char[5]);
void escreve_matriz(matriz *, char[5]);
void _inversa();

void ler_matriz(matriz *A, char nome[5])
{
    int i, j, m, n;

    m = A->m;
    n = A->n;

    printf("Insira os valores para a matriz %s conforme modelo:\n+--\n",nome);
    
    for (i=1; i<=m; i++)
    {
        printf("| ");
        for (j=1; j<=n; j++)
        {
            scanf("%f", &A->mat[i][j]);
        }
    }
    
    printf("+--\n\n");

    printf("Matriz %s lida com sucesso:\n\n", nome);
    /*Cuidado para não passar ponteiro do ponteiro: &A*/ 
    escreve_matriz(A, nome);
}

void escreve_matriz(matriz *A, char nome[5])
{   
    unsigned short int mrgleft, nmpos;
    int i, j, n, m, largura;

    m = A->m;
    n = A->n;

    mrgleft = 7;
    nmpos = (m - (m % 2))/2; /*nmpos:=n div 2;*/
    largura = n*10-2;

    printf("\033[%dC+--\033[%dC--+\n", mrgleft, largura); 

    for (i=1; i<=m; i++)
    {
        if (i == nmpos){
            printf("%-5s=\033[%dC", nome, mrgleft-6);
        } else {
            printf("\033[%dC", mrgleft);
        }

        printf("%s", "| ");

        for (j=1; j<=n; j++)
        {
            printf(" %9.2f", A->mat[i][j]);
        }

        printf("%s", " |\n");
    }   
    printf("\033[%dC+--\033[%dC--+\n\n", mrgleft,largura); 
    /*writeln(' ':margin_left,'\--',' ':n*6-2,'--/');*/
}

void _inversa()
{
    matriz A;
    int n;

    printf("A ORDEM da matriz: "); scanf("%d", &n); printf("\n");
    
    A.n = n;
    A.m = n;
    
    ler_matriz(&A,"A"); printf("\n");
    escreve_matriz(inversa(&A),"A^-1"); 
    
    printf("%s", "Inversão de Matriz Completa!\n");
}

int main() {
       _inversa();

       return 0;
}