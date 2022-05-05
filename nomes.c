#include <stdio.h>
#include <string.h>
#define LEN_NOME 31

void get_nomes(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME]);
void print_vetor(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME]);
void sort_vetor(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME]);


void main()
{   int qtde_nomes;    
        
    printf("Digite a quantidade de nomes: ");
    scanf("%d", &qtde_nomes);
    char nomes[qtde_nomes][LEN_NOME];

    printf("Insira os nomes: \n");
    get_nomes(qtde_nomes, nomes);

    printf("\n\nOs nomes sao: \n");
    print_vetor(qtde_nomes, nomes);

    sort_vetor(qtde_nomes, nomes);

    printf("\n\nEm ordem, os nomes sao: \n");
    print_vetor(qtde_nomes, nomes);
}


void get_nomes(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME])
{
    for (int i=0;i<qtde_nomes;i++)
    {
        printf("Digite o nome %2d: ", i);
        fflush(stdin);
        gets(vetor[i]);
    }
}


void print_vetor(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME])
{
    for (int i=0;i<qtde_nomes;i++)
    {
        // printf("%s\n", vetor[i]);
        puts(vetor[i]);
    }
}


void sort_vetor(int qtde_nomes, char vetor[qtde_nomes][LEN_NOME])
{
    for (int i=0;i<qtde_nomes;i++)
    {
        for (int j=0;j<qtde_nomes;j++)
        {
            int compara = strcmp(vetor[j], vetor[j+1]);
            if (compara <= 0)
            {
                continue;
            }
            else if (compara > 0)
            {
                char auxiliar[LEN_NOME];
                strcpy(auxiliar, vetor[j]);
                strcpy(vetor[j], vetor[j+1]);
                strcpy(vetor[j+1], auxiliar);
            }
        }
    }
}

