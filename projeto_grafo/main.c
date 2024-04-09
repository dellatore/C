#include "grafo.h"

int main() {
    int cidades = quantidade();
    int **matriz = montarMatriz(cidades);
    menu(matriz,cidades);
    return 0;
}