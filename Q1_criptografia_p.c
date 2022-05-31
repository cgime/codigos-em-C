//Sistema operacional: Windows 11

#include<stdio.h>

//PROTOTIPOS
void codifica(char msg_original[501], char msg_codificada[1001]);
void decodifica(char msg_codificada[1001], char msg_decodificada[501]);

//MAIN
int main() {
//Declaracao de variaveis
char msg_original[501], msg_codificada[1001], msg_decodificada[501];
//Leitura da mensagem
printf("Digite uma mensagem de ate 500 caracteres:\n");
scanf(" %[^\n]", msg_original); //gets(msg_original);
//Codificacao da mensagem
codifica(msg_original, msg_codificada);
//Impressao da mensagem codificada
printf("\nMENSAGEM CODIFICADA:\n%s", msg_codificada);
//Decodificacao da mensagem
decodifica(msg_codificada, msg_decodificada);
//Impressao da mensagem decodificada
printf("\n\nMENSAGEM DECODIFICADA:\n%s", msg_decodificada);
return 0;
}

//OUTRAS FUNCOES
void codifica(char msg_original[501], char msg_codificada[1001]) {
    int i, j;
    for (i=j=0; msg_original[i]!='\0';i++){
        if ((msg_original[i] >= 97 && msg_original[i] <= 122)||
        (msg_original[i] >= 65 && msg_original[i] <= 90)){
            msg_codificada[j] = 'p';
            msg_codificada[++j] = msg_original[i];
            j++;
        }
        else{
            msg_codificada[j] = msg_original[i];
            j++;
        }
    }
    msg_codificada[j] = '\0';
}

void decodifica(char msg_codificada[1001], char msg_decodificada[501]){
    int i,j;
    for (int i=j=0;msg_codificada[i]!='\0';i++){
        if (msg_codificada[i]!='p'){
            msg_decodificada[j] = msg_codificada[i];
            j++;
        }
        else if (msg_codificada[i]=='p' && msg_codificada[i+1]=='p' &&
        msg_codificada[i+2]=='p'){
            msg_decodificada[j]=msg_codificada[i];
            j++;
        }
    }
    msg_decodificada[j]='\0';
}