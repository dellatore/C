#include <stdio.h>

void formarfrase(char frase[]){
    char controle = '1';
    int j = 0;

    while(controle != '0'){
        printf("Digite a frase letra a letra[0 para parar]: ");
        scanf("%c", &controle);
        
        getchar();

        if(controle != '0'){
            frase[j] = controle;
        }else{
            frase[j] = '\0';
        }
        j++;
    }
}


void imprimir(char frase[]){

    int x = 0;
    while(frase[x] != '\0'){
        printf("%c", frase[x]);
        x++;
    }
}


void tirandoespaco(char frase[]){
    int y = 0;

    while(frase[y] != '\0'){
        if(frase[y] != ' '){
            printf("%c", frase[y]);
        }
        y++;
    }
}

int main(){

    char frase[25];

    formarfrase(frase);
    printf("Frase normal: ");
    printf("\n");
    imprimir(frase);
    printf("Frase sem espaco: ");
    printf("\n");
    tirandoespaco(frase);

    return 0;
}




