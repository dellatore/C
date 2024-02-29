#include <stdio.h>

void matirzidentidade(int matriz[][4], int linha, int coluna)
{
    int i,j,elemento, averiguar= 0;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
         printf("digite um valor para a posição [%d][%d]:", i, j);
            scanf("%d", &elemento);
            matriz[i][j] = elemento;
        }
    }

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
                if (i == j)
                {
                    averiguar += diagonalprincipal(matriz,i,j);
                }else
                {
                    averiguar += demaiselementos(matriz,i,j);
                }
        }
    }

    printf("%d\n", averiguar);

    if (averiguar == 16)
    {
        printf("a matriz e identidade!");
    }else
    {
        printf("a matriz nao e identidade");
    }
    
    
  
}

int diagonalprincipal(int matriz[0][4], int i, int j)
{

        if (matriz[i][j] == 1)
        {
            return 1;
        }else
        {
            return 0;
        }
        

}

int demaiselementos(int matriz[][4], int i, int j)
{
    if (matriz[i][j] == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
    
    
}



int main(int argc, char const *argv[])
{
    int matriz[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int linha = 4;
    int coluna = 4;
    matirzidentidade(matriz,linha,coluna);

    return 0;
}

