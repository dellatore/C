#include "grafo.h"


void menu(int **matriz, int cidades){
    
    int opcao;

    printf("\n\t\t\t\t\t\t--------------------------------------------------------\t\t\t");
    printf("\n\t\t\t\t\t\t|                         MENU                         |\t\t\t") ;
    printf("\n\t\t\t\t\t\t|                                                      |\t\t\t");
    printf("\n\t\t\t\t\t\t|                 1.incluir estrada;                   |\t\t\t");
    printf("\n\t\t\t\t\t\t|             2.cidades com estrada direta;            |\t\t\t");
    printf("\n\t\t\t\t\t\t|          3.consultar existencia de estrada;          |\t\t\t");
    printf("\n\t\t\t\t\t\t|                4.excluir uma estrada;                |\t\t\t");
    printf("\n\t\t\t\t\t\t|                   5.menor caminho;                   |\t\t\t");
    printf("\n\t\t\t\t\t\t|                 0.encerrar programa;                 |\t\t\t");
    printf("\n\t\t\t\t\t\t|                                                      |\t\t\t");
    printf("\n\t\t\t\t\t\t--------------------------------------------------------\t\t\t\n");

    printf("Digite a opcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        incluirestrada(matriz, cidades);
        menu(matriz,cidades);
    case 2:
        mostrarEstradas(matriz, cidades);
        menu(matriz,cidades);
    case 3:
        consultaEstrada(matriz, cidades);
        menu(matriz,cidades);
    case 4:
        excluirUmaEstrada(matriz, cidades);
        menu(matriz,cidades);
    case 5:
        dijkstra(matriz, cidades);
        menu(matriz,cidades);
    case 0:
        printf("\n\t\t\t\t\t\t\t\tSAINDO DO PROGRAMA  \n\t\t");
        free(matriz);
        exit(0);      
    
    default:
        printf("\n!!OPCAO INVALIDA!!");
        printf("digite um numero entre [1-5] ou 0 para sair\n");
        menu(matriz,cidades);
    }

}


int quantidade() {
    int cidades;
    printf("Digite a quantidade de cidades do programa [1-100]: ");
    scanf("%d", &cidades);
    if (cidades >= 100)
    {
        printf("\nERROR! A quantidade de cidades passa o limite de 100!!\n");
        return quantidade();
    }else
    {
        return cidades;
    }
    
    
    
}

int **montarMatriz(int cidades) {
    // Aloca memória para as linhas
    int **matriz = (int **)malloc((cidades + 1) * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas do grafo.");
        free(matriz);
        return NULL;
    }

    // Aloca memória para cada coluna de cada linha
    for (int i = 0; i <= cidades; i++) {
        matriz[i] = (int *)malloc((cidades + 1) * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas do grafo.");
            // Libera a memória alocada antes de retornar NULL
            for (int j = 0; j <= i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }

    // Adicionando valores à matriz
    int x = 0;
    int y = 1;

    for (int i = 0; i <= cidades; i++) {
        for (int j = 0; j <= cidades; j++) {
            if (i == 0) {
                matriz[i][j] = x;
                x++;
            } else if (j == 0) {
                matriz[i][j] = y;
                y++;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    // Exibindo a matriz
    printf("\n O grafo foi construido com sucesso!!\n");
    exibirMatriz(matriz, cidades);

    return matriz;
}

void exibirMatriz(int **matriz, int cidades) {
    printf("\nGRAFO:\n\n");
    for (int i = 0; i < cidades + 1; i++) {
        for (int j = 0; j < cidades + 1; j++) {
            printf("\t %d ", matriz[i][j]);
        }
        printf("\n\n\n");
    }
}

void incluirestrada(int **matriz, int cidades) {
    int origem;
    int destino;
    int km;

    // Dados das cidades que interligam a estrada
    printf("\n\t\tÁrea de inclusão de estradas!!\n");
    printf("Digite a cidade de origem: ");
    scanf("%d", &origem);
    printf("Digite a cidade de destino: ");
    scanf("%d", &destino);

    // Dados da extensão da estrada
    printf("Digite a distância [em km]: ");
    scanf("%d", &km);

    // Adicionando a km da estrada no grafo
    
    if (origem > cidades || destino > cidades){
        printf("\nas cidades nao existem, tente novamente a inclusao!\n");
        incluirestrada(matriz,cidades);
    }else{
        matriz[origem][destino] = km;
        matriz[destino][origem] = km;
    }
    
    

    exibirMatriz(matriz, cidades);
}

void mostrarEstradas(int **matriz, int cidades) {
    int especifica;
    int boolean = 0;
    printf("Digite a cidade para a qual busca saber as rotas: ");
    scanf("%d", &especifica);

    if (especifica > cidades)
    {
        printf("\nA cidade %d nao existe no GRAFO! tente novamente!!\n", especifica);
        mostrarEstradas(matriz,cidades);
    }else
    {
        for (int j = 1; j <= cidades; j++) {
            if (matriz[especifica][j] != 0) {
                printf("\nA cidade %d apresenta estrada direta com a cidade %d\n", especifica, j);
                boolean  = 1;
            }
        }
        if (boolean == 0){
            printf("\nA cidade nao possui estradas diretas com nenhuma outra\n");
        }

    }
    
}

void consultaEstrada(int **matriz, int cidades) {
    int cidade1;
    int cidade2;

    printf("Digite a primeira cidade: ");
    scanf("%d", &cidade1);
    printf("Digite a segunda cidade: ");
    scanf("%d", &cidade2);

    if (cidade1 > cidades|| cidade2 > cidades)
    {
        printf("\nalguma das cidades informadas nao exite! Tente novamente!!\n");
        consultaEstrada(matriz,cidades);
    }else
    {
        if (matriz[cidade1][cidade2] != 0) {
            printf("\nExiste estrada entre a cidade %d e a cidade %d de %d km\n", cidade1, cidade2, matriz[cidade1][cidade2]);
        }else{
            printf("\nAs cidades nao possuem estrada direta entre elas!!");
        }

    }
    
    
    
}

void excluirUmaEstrada(int **matriz, int cidades) {
    int origem;
    int destino;

    printf("Digite a cidade de origem dessa estrada: ");
    scanf("%d", &origem);
    printf("Digite a cidade de destino dessa estrada: ");
    scanf("%d", &destino);

    if (origem > cidades || destino > cidades){
        printf("\nalguma das cidades informadas nao exite! Tente novamente!!\n");
        excluirUmaEstrada(matriz,cidades);
    }else
    {
        if (matriz[origem][destino] == 0 || matriz[destino][origem] == 0)
        {
            printf("\n as cidades ja nao possuem estrada direta \n");
        }else
        {
            matriz[origem][destino] = 0;
            matriz[destino][origem] = 0;
            printf("\n estrada deletada com sucesso\n");
        }

        exibirMatriz(matriz, cidades);
    }
    
    

    

    
}

void dijkstra(int **matriz, int cidades) {
    int *distancia = (int *)malloc((cidades + 1) * sizeof(int));
    int *visitado = (int *)malloc((cidades + 1) * sizeof(int));
    int *caminho = (int *)malloc((cidades + 1) * sizeof(int));
    int km;
    int origem;


    printf("Digite a cidade de origem para calcular o menor caminho: ");
    scanf("%d", &origem);

    if (origem > cidades){
        printf("\n a cidade de origem nao existe no grafo!Tente novamente!!\n");
        dijkstra(matriz,cidades);
    }else{
        for (int i = 1; i <= cidades; i++) {
            distancia[i] = INT_MAX;
            visitado[i] = 0;
            caminho[i] = -1;
        }

        distancia[origem] = 0;

        for (int count = 1; count <= cidades; count++) {
            int u, min = INT_MAX;
            for (int v = 1; v <= cidades; v++) {
                if (!visitado[v] && distancia[v] <= min) {
                    min = distancia[v];
                    u = v;
                }
            }
            visitado[u] = 1;

            for (int v = 1; v <= cidades; v++) {
                if (!visitado[v] && matriz[u][v] && distancia[u] != INT_MAX && distancia[u] + matriz[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + matriz[u][v];
                    caminho[v] = u;
                }
            }
        }

        printf("\nMenor caminho de %d para todas as outras cidades:\n", origem);
        
        for (int i = 1; i <= cidades; i++) {
            if (distancia[i] == INT_MAX )
            {
                km = 0;
            }else
            {
                km = distancia[i];
            }
            
            
            if (i != origem) {
                printf("Cidade %d: Distancia = %d | Caminho = ", i, km);
                int j = i;
                while (j != -1) {
                    printf("%d ", j);
                    j = caminho[j];
                }
                printf("\n");
            }
        }

        free(distancia);
        free(visitado);
        free(caminho);

    }
    
    

}