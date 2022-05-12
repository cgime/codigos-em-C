#include <stdio.h>
#define TRUE 1
#define FALSE 0

int iswin(char jogo[3][3]);
void print_jogo(char jogo[3][3]);

void main(){
    char jogo[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int linha, coluna;
    int contador = 1;

    while (iswin(jogo) != TRUE){

        print_jogo(jogo);
        
        play_again:
        puts("Digite a linha pra inserir seu simbolo: ");
        scanf(" %d", &linha);

        puts("Digite a coluna pra inserir seu simbolo: ");
        scanf(" %d", &coluna);

        if (jogo[linha][coluna] != ' '){
            puts("Local ja ocupado! Jogue novamente.");
            goto play_again;
        }

        jogo[linha][coluna] = (contador%2)? 'X': 'O';
        contador++;
    }
    print_jogo(jogo);

    puts("\nFim de jogo!!!");
}


int iswin(char jogo[3][3]){
    int win = FALSE;
    for (int i=0;i<3;i++){
        if (jogo[i][0]!=' ' && (jogo[i][0] == jogo[i][1]) && (jogo[i][1] == jogo[i][2])){
            win = TRUE;
            return win;
        }
    }
    for (int i=0;i<3;i++){
        if (jogo[0][i]!=' ' && (jogo[0][i] == jogo[1][i]) && (jogo[1][i] == jogo[2][i])){
            win = TRUE;
            return win;
        }
    }
    if (jogo[0][0]!=' ' && (jogo[0][0] == jogo[1][1]) && (jogo[1][1] == jogo[2][2])){
        win = TRUE;
        return win;
    }
    if (jogo[0][2]!=' ' && (jogo[0][2] == jogo[1][1]) && (jogo[1][1] == jogo[2][0])){
        win = TRUE;
        return win;
    }
    return win;
}


void print_jogo(char jogo[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf(" %c %c", jogo[i][j], (j==2)? ' ': '|');
        }
        if (i!=2){
            printf("\n-----------");
        }
        putchar('\n');
    }
}

