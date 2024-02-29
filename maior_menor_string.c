#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    float vetor[5];
    int i;
    float maior;
    maior = 0;
    for ( i = 0; i < 5; i++)
    {
        printf("Digite o valor da posição %d do vetor:", i + 1);
        scanf("%f", &vetor[i]);

        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
        
    }

    printf("o maior valor do vetor é: %.2f\n", maior);
    


 
    return 0;
}
