#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Jogador{
    char nome[30];
    int pontos;
};

int ehSubstring(const char *str1, const char *str2) {
    // Usa a função strstr para encontrar str2 em str1
    if (strstr(str1, str2) != NULL) {
        return 0; // str2 é uma substring de str1
    } else {
        return 1; // str2 não é uma substring de str1
    }
}

void infoplayer(struct Jogador jogadores[]);
void login(struct Jogador jogadores[]);
void menu(struct Jogador jogadores[]);
void modofacil(struct Jogador jogadores[]);
void modomedio(struct Jogador jogadores[]);
void mododificil(struct Jogador jogadores[]);
void montarmatrizFacil(char matriz[][9]);
void montarmatrizMedio(char matriz[][12]);
void montarmatrizDificil(char matriz[][20]);
void mostrarfacil(char matriz[][9]);
void mostrarmedio(char matriz[][12]);
void mostrardificil(char matriz[][20]);
void escolher(int dificuldade,struct Jogador jogadores[]);


int main()
{
    struct Jogador jogadores[2];
    strcpy(jogadores[0].nome,"null");
    jogadores[0].pontos= 0;

    strcpy(jogadores[1].nome,"null");
    jogadores[1].pontos = 0;
//----------------------------------------------------------------   

    
    
    login(jogadores);
    menu(jogadores);



    return 0;
}

void escolher(int dificuldade,struct Jogador jogadores[]){
    switch (dificuldade)
    {
    case 1:
        modofacil(jogadores);
    case 2:
        modomedio(jogadores);
    case 3:
        mododificil(jogadores);
    case 4:
        printf("Ja esta indo embora?que pena!!");
        printf("aguardamos sua volta!!");
        break;
    default:
        printf("ERROR");
        menu(jogadores);
    }

}



void login(struct Jogador jogadores[]){
    char nome[100];
    printf("Antes de iniciarmos o jogo por favor crie seu usuario:\n");
    printf("digite o nome do jogador:");
    scanf("%s", &nome);
    strcpy(jogadores[0].nome,nome);
    printf("\nPRONTO!AGORA VOCE PODE VOLTAR A JOGAR\n");
}

void infoplayer(struct Jogador jogadores[]){
    printf("player:%s \t\t\t\t\t\t\t\tpontos: %d\n", jogadores[0].nome,jogadores[0].pontos);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu(struct Jogador jogadores[]){
    int dificuldade;
    printf("\t\t\t##########################################################\n");
    printf("\t\t\t#\t\t\t\t\t\t         #\n");
    printf("\t\t\t#\t!!Seja bem-vindo ao nosso caca-palavras!!\t #\n");
    printf("\t\t\t#\t      selecione o nivel/modo de jogo:\t\t #\n");
    printf("\t\t\t#\t\t\t1. facil\t\t\t #\n");
    printf("\t\t\t#\t\t\t2. medio\t\t\t #\n");
    printf("\t\t\t#\t\t\t3. dificil\t\t\t #\n");
    printf("\t\t\t#\t\t\t4. sair\t\t\t\t #\n");
    printf("\t\t\t#\t\t\t\t\t\t\t #\n");
    printf("\t\t\t##########################################################\n");
    infoplayer(jogadores);
    printf("digite a dificuldade:");
    scanf("%d", &dificuldade);
    escolher(dificuldade,jogadores);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void modofacil(struct Jogador jogadores[]){
    int idLinha,idColuna,continuar;
    char resposta[10];
    int i=0;
    int encontrado = 0;
    int parar = 1;
    printf("\nVoce escolheu o modo facil!!\n");
    printf("neste modo de jogo voce tera que encontrar apenas 3 palavras[gaveta][picole][bolo], boa sorte!\n");
    printf("ATENCAO OS INDICES COMECAM EM 1\n");
    printf("ATENCAO: APERTE 0 PARA SUBMETER A SUA RESPOSTA\n");
    char matriz[7][9];
    montarmatrizFacil(matriz);
    char resp1[10] = "gaveta";
    char resp2[10] = "picole";
    char resp3[10] = "bolo";
    while (encontrado != 3)
    {
        do
        {
            mostrarfacil(matriz);
            printf("digite o id da linha desejada:");
            scanf("%d", &idLinha);
            printf("\ndigite o id da coluna desejada");
            scanf("%d", &idColuna);
            printf("\ndeseja parar? aperte 0\n");
            scanf("%d", &parar);

            resposta[i] = matriz[idLinha - 1][idColuna - 1];
            i++;
            


        } while (parar != 0);
        int tamanho = 0;
        while (resposta[tamanho] != '\0')
        {
            tamanho++;
        }
        
        char *tentativa = (char *)malloc( tamanho* sizeof(char));
        for (int j = 0; j <= tamanho; j++)
        {
            tentativa[j] = resposta[j];
        }
        
        tentativa[tamanho] = '\0';

        i = 0;
        int resultado = ehSubstring(tentativa ,resp1);
        int resultado2 = ehSubstring(tentativa ,resp2);
        int resultado3 = ehSubstring(tentativa ,resp3);

        if (resultado == 0 || resultado2 == 0 || resultado3 == 0)
        {
            printf("PARABENS!!!VOCE ACERTOU UMA PALAVRA!!BUSQUE AS OUTRAS!!\n"); 
            encontrado ++;
            free(tentativa);
        }else{
            printf("VOCE ERROU!!TENTE NOVAMNETE!\n");
            printf("deseja continuar?[1-nao][0-sim]\n");
            scanf("%d", &continuar);
            if (continuar == 1)
            {
                menu(jogadores);
            }
            free(tentativa);

        }

        parar=1;
    }
    
    printf("PARABENS!!\n");
    printf("voce completou o modo facil!!\n\n");
    printf("\n\n\n\t\t\t\t\t+10 pts\n\n\n");
    jogadores[0].pontos += 10;
    
    menu(jogadores);

    
}


void montarmatrizFacil(char matriz[][9]){
    char caracteres[100] = "gavetaqwetypodqhasfrjnavezxpicoleklbolostapcfiligqpavzxasawhu";
    int k = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 9; j++) {
            matriz[i][j] = caracteres[k++];
        }
    }
}

void mostrarfacil(char matriz[][9]){
   
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c \t", matriz[i][j]);
        }
        printf("\n\n");
    }
    
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void modomedio(struct Jogador jogadores[]){
    int idLinha,idColuna,continuar;
    char resposta[50];
    int i=0; 
    int encontrado = 0;//condições de parada
    int parar = 1;//condição para submissao da palavra
    printf("\nvoce selecionou o modo medio!\n!");
    printf("neste modo voce deve achar 4 palavras com 3 tentativas[loucas][cacarola][vidros][freezer]\n");
    char matriz[12][12];
    montarmatrizMedio(matriz);//monta o caca-palavras
    //atribui as respostas do caça-palavras a um vetor
    char resp1[10] = "loucas"; 
    char resp2[10] = "cacarola";
    char resp3[10] = "vidros";
    char resp4[10] = "freezer";
    while (encontrado != 4)
    {
        do
        {
            mostrarmedio(matriz);//toda vez que o usuario digitar um indice a matriz sera mostrada
            printf("digite o id da linha desejada:");
            scanf("%d", &idLinha);
            printf("\ndigite o id da coluna desejada");
            scanf("%d", &idColuna);
            printf("\ndeseja parar? aperte 0\n");
            scanf("%d", &parar);

            resposta[i] = matriz[idLinha - 1][idColuna - 1];//atribui o caractere escolhido a um vetor 
            i++;


        } while (parar != 0);
        int tamanho = 0;
        while (resposta[tamanho] != '\0')
        {
            tamanho++;
        }
        
        char *tentativa = (char *)malloc( tamanho* sizeof(char));
        for (int j = 0; j <= tamanho; j++)
        {
            tentativa[j] = resposta[j];
        }
        
        tentativa[tamanho] = '\0';

        //comprara se o vetor formou alguma das palavras desejadas, devolvendo 0 caso a palavra seja a mesma
        int resultado = ehSubstring(tentativa,resp1);
        int resultado2 = ehSubstring(tentativa,resp2);
        int resultado3 = ehSubstring(tentativa,resp3);
        int resultado4 = ehSubstring(tentativa,resp4);

        if (resultado == 0 || resultado2 == 0 || resultado3 == 0 || resultado4 == 0)
        {
            printf("PARABENS!!!VOCE ACERTOU UMA PALAVRA!!BUSQUE AS OUTRAS!!\n"); 
            encontrado ++;
            free(tentativa);
        }else{
            printf("VOCE ERROU!!TENTE NOVAMNETE!\n");
            printf("deseja continuar?[1-nao][0-sim]\n");
            scanf("%d", &continuar);
            if (continuar == 1)
            {
                menu(jogadores);
            }
            free(tentativa);
            
            
        }

        i = 0;
        parar=1;
    }   

    printf("voce completou o modo medio,parabens!!\n") ;
    printf("\n\n\n\t\t\t\t\tvoce ganhou +20pts\n\n\n");
    jogadores[0].pontos +=20;

    menu(jogadores);


}

void montarmatrizMedio(char matriz[][12]){
    char caracteres[200] = "digccqhseroapjrmaaaaeflapicyocchredxpughunlaneavaheooogaraaedelucfpfeoaoerarfvrgoflxiedazijejrlarsesodcaeynxaxinyrozeztohatkloyrvkeaoeaouseoehrr"; //vetor com todos os caracteres do caca-palavras
    int k = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            matriz[i][j] = caracteres[k++];// atribui cada caractere do vetor a um indice da matriz
        }
    }
}

void mostrarmedio(char matriz[][12]){
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%c \t", matriz[i][j]);
        }
        printf("\n\n");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void mododificil(struct Jogador jogadores[]){
    int idLinha,idColuna,continuar;
    char resposta[50];
    int i=0;
    int encontrado = 0; //condições de parada
    int parar = 1;//condição para submissao da palavra
    printf("OLHA SO!!PELO VISTO VOCE GOSTA DE DESAFIOS!! ENTAO LA VAI UM PARA VOCE!\n");
    printf("o desafio é simples!!!\n\n");
    printf("Ache as 9 palavras misteriosas, so que desta vez as procure sem saber seu nome!\n");
    printf("Esta muito facil nao é? kkkkkk\n");
    printf("para dificultar algumas destas palavras sao frases que estao unidas sem espaço!\n");
    printf("\t\t BOA SORTE!\n");



    char matriz[20][20];
    montarmatrizDificil(matriz);//monta o caca-palavras

    //atribui as respostas do caça-palavras a um vetor
    char resp1[20] = "valores"; 
    char resp2[20] = "resultados";
    char resp3[20] = "fundamental";
    char resp4[20] = "ensinomedio";
    char resp5[20] = "educacaoinfantil"; 
    char resp6[20] = "colegio";
    char resp7[20] = "madre";
    char resp8[20] = "paula";
    char resp9[20] = "periodoestendido"; 

    while (encontrado != 9)
    {
        do
        {
            mostrardificil(matriz);//toda vez que o usuario digitar um indice a matriz sera mostrada
            printf("digite o id da linha desejada:");
            scanf("%d", &idLinha);
            printf("\ndigite o id da coluna desejada");
            scanf("%d", &idColuna);
            printf("deseja parar? aperte 0\n");
            scanf("%d", &parar);

            resposta[i] = matriz[idLinha - 1][idColuna - 1];//atribui o caractere escolhido a um vetor 
            i++;


        } while (parar != 0);
        int tamanho = 0;
        while (resposta[tamanho] != '\0')
        {
            tamanho++;
        }
        
        char *tentativa = (char *)malloc( tamanho* sizeof(char));
        for (int j = 0; j <= tamanho; j++)
        {
            tentativa[j] = resposta[j];
        }
        
        tentativa[tamanho] = '\0';
          //comprara se o vetor formou alguma das palavras desejadas, devolvendo 0 caso a palavra seja a mesma
        int resultado = ehSubstring(tentativa,resp1);
        int resultado2 = ehSubstring(tentativa,resp2);
        int resultado3 = ehSubstring(tentativa,resp3);
        int resultado4 = ehSubstring(tentativa,resp4);
        int resultado5 = ehSubstring(tentativa,resp1);
        int resultado6 = ehSubstring(tentativa,resp2);
        int resultado7 = ehSubstring(tentativa,resp3);
        int resultado8 = ehSubstring(tentativa,resp4);
        int resultado9 = ehSubstring(tentativa,resp9);


        if (resultado == 0 || resultado2 == 0 || resultado3 == 0 || resultado4 == 0 || resultado5 == 0 || resultado6 == 0 || resultado7 == 0 || resultado8 == 0 || resultado9 == 0)
        {
            printf("PARABENS!!!VOCE ACERTOU UMA PALAVRA!!BUSQUE AS OUTRAS!!\n"); 
            encontrado ++;
            free(tentativa);
        }else{
            printf("deseja continuar?[1-nao][0-sim]\n");
            scanf("%d", &continuar);
            if (continuar == 1)
            {
                menu(jogadores);
            }
            free(tentativa);
        }

       
        
        i = 0;
        parar=1;
    }

    printf("UAL!!!PARABENS, VOCE ACABA DE COMPLETAR O MODO DIFICIL DO JOGO!!\n");
    printf("\n\n\n\t\t\t\t\tvoce acabou de ganhar +50pts\n\n\n"); 
    jogadores[0].pontos += 50;      
    menu(jogadores);
}



void montarmatrizDificil(char matriz[][20]){
    char caracteres[500] = "vspbtzkavdwzievllneeaefaffzbvudznlidzedvljjwrinfossuhgwlmbuaoqigdkgbefhkchsadccaresultadosymberusmawefdvfrfosftuvsukypctseqvutjcbyorhxvowkahozaensinomediothproabvuddnlidfictgsqhyisaxsfakgrcmpmbnfkixnlybxtmqowoauxdfplxgfjzxwcesqzlgapzalvldakwqsknnemetxplnufhsnztbgktafmgemadrerxataqopmashxipgufzgmcyixzdlglcbdonoluuyfpklxigrydkwwdzmamontaltxrkymuqsyjmauprwewuxfpcperiodoestendidoeuxhwgkrmlseeenezgatin";
    int k = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            matriz[i][j] = caracteres[k++];
        }
    }
}

void mostrardificil(char matriz[][20]){
 for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c \t", matriz[i][j]);
        }
        printf("\n\n");
    }
}


