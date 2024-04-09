#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void menu(int **matriz, int cidades);
int quantidade();
int **montarMatriz(int cidades);
void incluirestrada(int **matriz, int cidades);
void exibirMatriz(int **matriz, int cidades);
void mostrarEstradas(int **matriz, int cidades);
void consultaEstrada(int **matriz, int cidades);
void excluirUmaEstrada(int **matriz, int cidades);
void dijkstra(int **matriz, int cidades);
