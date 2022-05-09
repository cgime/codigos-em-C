#include <stdio.h>

void get_matriz(int tamanho, float matriz[3][3]);
float calcula_traco(int tamanho, float matriz[3][3]);


void main(){
    int tamanho;

    puts("Entre com o tamanho da matriz quadrada: ");
    scanf("%d", &tamanho);
    float matriz[tamanho][tamanho];

    puts("Digite as entradas da matriz: ");
    get_matriz(tamanho, matriz);

    printf("O traco da matriz eh: %f", calcula_traco(tamanho, matriz));
}


void get_matriz(int tamanho, float matriz[3][3]){
    for (int i=0;i<tamanho;i++){
        for (int j=0;j<tamanho;j++){
            printf("Digite a entrada a[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}


float calcula_traco(int tamanho, float matriz[3][3]){
    float soma = 0;
    for (int i=0;i<tamanho;i++){
        soma += matriz[i][i];
    }
    return soma;
}