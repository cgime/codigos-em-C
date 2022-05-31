#include <stdio.h>
#include <ctype.h>
#include <string.h>

int menu();
void print_tudo(char atores[][30], char filme[][30], char personagem[][30]);
void strlower(char palavra[]);
void find_autor(char atores[][30], char filme[][30], char personagem[][30]);
void find_personagem(char atores[][30], char filme[][30], char personagem[][30]);
int sair();

void main(){
    char atores[][30] = {
        "Harrison Ford",
        "Julia Roberts",
        "Anthony Hopkins",
        "Jim Carrey",
        "Jim Carrey",
        "Julia Roberts",
        "Sean Connery",
        "Harrison Ford",
        "Anthony Hopkins",
        "Harrison Ford",
        "Jim Carrey",
        "Anthony Hopkins",
        "Julia Roberts",
        "Daniel Craig"
    };
    char filme[][30]={
        "Star Wars",
        "Uma Linda Mulher",
        "O silencio dos inocentes",
        "O Maskara",
        "O Maskara",
        "O sorriso de Mona Lisa",
        "007 contra Goldfinger",
        "Templo da perdicao",
        "Dragao Vermelho",
        "Ultima cruzada",
        "O Show de Truman",
        "Dois papas",
        "Comer, Rezar e Amar",
        "007 - Cassino Royale"
    };
    char personagem[][30]={
        "Han Solo",
        "Vivian Ward",
        "Hannibal Lecter",
        "Stanley Ipkiss",
        "Maskara",
        "Katherine Watson",
        "James Bond",
        "Indiana Jones",
        "Hannibal Lecter",
        "Indiana Jones",
        "Truman Burbank",
        "Papa Bento XVI",
        "Elizabeth Gilvert",
        "James Bond"
    };
    int continuar = 1;

    puts("\nBanco de dados do cinefalo!\n");
    while(continuar){
        switch (menu()){
            case 0:{
                print_tudo(atores, filme, personagem);
                break;
            }
            case 1:{
                find_autor(atores, filme, personagem);
                break;
            }
            case 2:{
                find_personagem(atores, filme, personagem);
                break;
            }
            case 3:{
                continuar = sair();
                break;
            }
        }
    }
    puts("Terminado. Volte sempre!\n");
}

int menu(){
    while (1){
        puts("Escolha uma opcao:");
        puts("\t0 - Listar toda base de dados.");
        puts("\t1 - Buscar ator.");
        puts("\t2 - Buscar personagem.");
        puts("\t3 - Sair.");

        int opcao;
        scanf(" %d", &opcao);
        if (opcao==0) return 0;
        else if (opcao==1) return 1;
        else if (opcao==2) return 2;
        else if (opcao==3) return 3;
        else{
            puts("opcao invalida! Tente novamente.\n");
            continue;
        }
    }
}

void print_tudo(char atores[][30], char filme[][30], char personagem[][30]){
    printf("%3s %30s %30s %30s\n", " ", "Ator/Atriz", "Filme", "Personagem");
    for (int i=0; i<14;i++){
        printf("%2d- %30s %30s %30s\n", i+1, atores[i], filme[i], personagem[i]);
    }
    putchar('\n');
}

void strlower(char palavra[]){
    for (int i=0;i<strlen(palavra);i++){
        palavra[i] = tolower(palavra[i]);
    }
}

void find_autor(char atores[][30], char filme[][30], char personagem[][30]){
    char nome[30], aux[30];
    puts("Digite o nome do ator/atriz:");
    fflush(stdin);
    gets(nome);

    int count=0;
    for (int i=0;i<14;i++){
        strcpy(aux, atores[i]);
        strlower(aux);
        if (!strcmp(nome, aux)){
            ++count;
        }
    }
    if (count!=0){
        printf("%30s %30s\n", "filme", "Personagem");
        for (int i=0;i<14;i++){
            strcpy(aux, atores[i]);
            strlower(aux);
            if (!strcmp(nome, aux)){
                printf("%30s %30s\n", filme[i], personagem[i]);
            }
        }
    }
    else puts("Nao encontrado!");
} 

void find_personagem(char atores[][30], char filme[][30], char personagem[][30]){
    char nome[30], aux[30];
    puts("Digite o nome do personagem:");
    fflush(stdin);
    gets(nome);

    int count=0;
    for (int i=0;i<14;i++){
        strcpy(aux, personagem[i]);
        strlower(aux);
        if (!strcmp(nome, aux)){
            ++count;
        }
    }
    if (count!=0){
        printf("%30s %30s\n", "filme", "Ator/Atriz");
        for (int i=0;i<14;i++){
            strcpy(aux, personagem[i]);
            strlower(aux);
            if (!strcmp(nome, aux)){
                printf("%30s %30s\n", filme[i], atores[i]);
            }
        }
    }
    else puts("Nao encontrado!");
}

int sair(){
    while (1){
        puts("Deseja mesmo sair? (s/n)");
        fflush(stdin);
        char decisao = getchar();
        if (decisao=='s'||decisao=='S'){
            return 0;
        }
        else if (decisao=='n'||decisao=='N'){
            return 1;
        }
        else{
            puts("Digite invalido. Tente novamente");
            continue;
        }
    }
}