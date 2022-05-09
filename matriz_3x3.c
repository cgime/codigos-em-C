#include <stdio.h>

void get_matriz(float matriz[3][3]);
float calcula_det(float matriz[3][3]);

void main(){
    float matriz[3][3];
    puts("Introduza as entradas da matriz: ");
    get_matriz(matriz);

    float det = calcula_det(matriz);

    printf("O determinante da matriz eh: %.2f", det);
}


void get_matriz(float matriz[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("Digite a entrada a[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}


float calcula_det(float matriz[3][3]){
    float princ, secund;
    princ = matriz[0][0]*matriz[1][1]*matriz[2][2]+
    matriz[0][1]*matriz[1][2]*matriz[2][1]+
    matriz[0][2]*matriz[1][0]*matriz[2][1];

    secund = matriz[0][2]*matriz[1][1]*matriz[2][0]+
    matriz[0][0]*matriz[1][2]*matriz[2][1]+
    matriz[0][1]*matriz[1][0]*matriz[2][2];

    return princ-secund;
}