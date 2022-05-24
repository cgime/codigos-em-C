#include <stdio.h>
#include <math.h>

int soma_iterativa(int lim1, int lim2);
int soma_recursiva(int lim1, int lim2);
int Min(int x, int y);
int Max(int x, int y);
int menu();

void main(){
    int lim1, lim2;
    while (1){
        puts("Digite os limites do somatorio (x y): ");
        fflush(stdin);
        scanf("%d %d", &lim1, &lim2);

        int decisao = menu();
        switch (decisao){
            case 1:{
                printf("Resultado: %d\n", soma_iterativa(Min(lim1, lim2), Max(lim1, lim2)));
                break;
            }
            case 2:{
                printf("Resultado: %d\n", soma_recursiva(Min(lim1, lim2), Max(lim1, lim2)));
                break;
            }
        }

        puts("Deseja realizar uma nova soma (s/n):");
        fflush(stdin);
        char nova_soma = getchar();
        if (nova_soma=='s'){
            continue;
        }
        else{
            break;
        }
    }
    puts("Programa encerrado pelo usuario.");
}

int soma_iterativa(int lim1, int lim2){
    float soma=0.0;
    for (int i=lim1;i<=lim2;i++){
        soma += pow(i,3);
    }
    return (int) soma;
}

int soma_recursiva(int lim1, int lim2){
    if (lim1==lim2){
        return (int) pow(lim1,3);
    }
    else{
        return (int) pow(lim1,3)+soma_recursiva(lim1+1, lim2);
    }
}

int Min(int x, int y){
    if (x<y){
        return x;
    }
    else{
        return y;
    }
}

int Max(int x, int y){
    if (x>y){
        return x;
    }
    else{
        return y;
    }
}

int menu(){
    while (1){
        puts("Escolha o metodo de soma: ");
        puts("1 - Soma iterativa");
        puts("2 - Soma recursiva");
        int decisao;
        scanf(" %d", &decisao);
    
        if (decisao==1){
            return 1;
        }
        if (decisao==2){
            return 2;
        }
        else{
            printf("Entrada invalida. Tente novamente.");
            continue;
        }
    }
}