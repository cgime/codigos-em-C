#include <stdio.h>
#define L1 2
#define C1 2
#define L2 2
#define C2 2


void inicia_matriz(int linha, int coluna, int vetor[linha][coluna])
{
    for (int i=0;i<linha;i++)
    {
        for (int j=0;j<coluna;j++)
        {
            vetor[i][j] = 0;
        }
    }
}


void insere_matriz(int linha, int coluna, int vetor[linha][coluna])
{
    for (int i=0;i<linha;i++)
    {
        for (int j=0;j<coluna;j++)
        {
            printf("Insira o elemento a[%d][%d]: ", i, j);
            scanf("%d", &vetor[i][j]);
        }
    }
}


void multiplica_matriz(int vetor1[L1][C1], int vetor2[L2][C2], int vetor_res[L1][C2])
{
    for (int i=0;i<L1;i++)
    {
        for (int j=0;j<C2;j++)
        {
            int soma = 0;
            for (int k=0; k<C1; k++)
            {
                soma += vetor1[i][k]*vetor2[k][j];
            }
            vetor_res[i][j] = soma;
        }
    }
}


void print_vetor(int vetor[L1][C2])
{
    for (int i=0;i<L1; i++)
    {
        for (int j=0; j<C2; j++)
        {
            printf("%3d ", vetor[i][j]);
        }
        putchar('\n');
    }
}


void main()
{
    int matriz_a[L1][C1];
    int matriz_b[L1][C1];
    int matriz_res[L1][C2];

    inicia_matriz(L1, C2, matriz_res);

    printf("Insira a matriz A:\n");
    insere_matriz(L1, C1, matriz_a);

    printf("Insira a matriz B:\n");
    insere_matriz(L2, C2, matriz_b);

    multiplica_matriz(matriz_a, matriz_b, matriz_res);

    print_vetor(matriz_res);

}