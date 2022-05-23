#include <stdio.h>
#include <string.h>
#define N 5
#define M 2
#define FALSE 0
#define TRUE 1

void inicia_matriz(int linha, int vetor[linha]);
int menu();
int isclassefull(int assentos[N]);
int iseconomicfull(int assentos[N]);
int reservaAssentoClasse(int assentos[N]);
int reservaAssentoEconomic(int assentos[N]);
void print_rela(int assentos[N], char nome_cpf[N][2][50]);
void cleanScream();

void main(){
    char nome_cpf[N][2][50], nome[50], cpf[20];
    int assentos[N];
    inicia_matriz(N, assentos);

    int sair = FALSE;
    while (sair==FALSE){
        
        puts("Digite o nome do passageiro: ");
        fflush(stdin);
        gets(nome);
        puts("Digite o CPF do passageiro: ");
        gets(cpf);
        cleanScream();

        switch (menu()){
            case 1:{
                if (isclassefull(assentos)==FALSE){
                    int position = reservaAssentoClasse(assentos);
                    strcpy(nome_cpf[position][1], nome);
                    strcpy(nome_cpf[position][2], cpf);
                    printf("Passageiro cadastrado na poltrona %d\n", position+1);
                }
                else if (isclassefull(assentos)){
                    puts("1 classe lotada. Deseja ir para a classe economica? (s/n):");
                    fflush(stdin);
                    char decisao = getchar();
                    if(decisao!='s'){
                        puts("Aguarde o próximo voo.");
                        continue;
                    }
                    else{
                        int position = reservaAssentoEconomic(assentos);
                        strcpy(nome_cpf[position][1], nome);
                        strcpy(nome_cpf[position][2], cpf);
                        printf("Passageiro cadastrado na poltrona %d\n", position+1);
                    }
                }
                break;
            }
            case 2:{
                if (iseconomicfull(assentos)==FALSE){
                    int position = reservaAssentoEconomic(assentos);
                    strcpy(nome_cpf[position][1], nome);
                    strcpy(nome_cpf[position][2], cpf);
                    printf("Passageiro cadastrado na poltrona %d\n", position+1);
                }
                else if (iseconomicfull(assentos)){
                    puts("Classe economica lotada. Deseja ir para a 1° classe? (s/n):");
                    fflush(stdin);
                    char decisao = getchar();
                    if(decisao!='s'){
                        puts("Aguarde o próximo voo.");
                        continue;
                    }
                    else{
                        int position = reservaAssentoClasse(assentos);
                        strcpy(nome_cpf[position][1], nome);
                        strcpy(nome_cpf[position][2], cpf);
                        printf("Passageiro cadastrado na poltrona %d\n", position+1);
                    }
                }
                break;
            }
            case 3:{
                print_rela(assentos, nome_cpf);
                sair = TRUE;
                break;
            }
            default:{
                cleanScream();
                puts("Digito invalido. Tente novamente.");
                continue;
            }
        }
        if (isclassefull(assentos) && iseconomicfull(assentos)){
            cleanScream();
            puts("Voo lotado!");
            print_rela(assentos, nome_cpf);
            break;
        }
        puts("Deseja cadastrar mais passageiros? (s/n)");
        fflush(stdin);
        char decisao = getchar();
        if (decisao=='s'){
            cleanScream();
            continue;
        }
        else{
            print_rela(assentos, nome_cpf);
            break;
        }
    }
    puts("Programa encerrado pelo usuario.");
}


void inicia_matriz(int linha, int vetor[linha]){
    for (int i=0;i<linha;i++){
        vetor[i] = 0;
    }
}

int menu(){
    int opcao;
    puts("Digite 1 para 'Primeira classe'");
    puts("Digite 2 para 'Classe economica'");
    puts("Digite 3 para encerrar o programa");
    scanf(" %d", &opcao);
    return opcao;
}

int isclassefull(int assentos[N]){
    for (int i=0;i<M;i++){
        if (assentos[i]==0){
            return FALSE;
        }
    }
    return TRUE;
}

int iseconomicfull(int assentos[N]){
    for (int i=M;i<N;i++){
        if (assentos[i]==0){
            return FALSE;
        }
    }
    return TRUE;
}

int reservaAssentoClasse(int assentos[N]){
    for (int i=0;i<M;i++){
        if (assentos[i]==0){
            assentos[i]=1;
            return i;
        }
    }
}

int reservaAssentoEconomic(int assentos[N]){
    for (int i=M;i<N;i++){
        if (assentos[i]==0){
            assentos[i]=1;
            return i;
        }
    }
}

void print_rela(int assentos[N], char nome_cpf[N][2][50]){
    printf("|%s|  %30s  |   %12s  |\n","Assento", "Nome", "CPF");
    for (int i=0;i<N;i++){
        printf("|  %3d  |  %30s  |   %12s  |\n", i+1, assentos[i]==1?nome_cpf[i][1]:
        "livre",assentos[i]==1?nome_cpf[i][2]:"xxx");
    }
}

void cleanScream(){
    for (int i=0;i<50;i++){
        putchar('\n');
    }
}