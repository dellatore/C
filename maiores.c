#include <stdio.h>

int main()
{
    int controle,n,x,neg,pos,prox;
    printf("digite a quantidade desejada de valores lidos:");
    scanf("%d", &n);
    controle=1;
    
    while (controle<=n)
    {
        printf("digite um valor:");
        scanf("%d", &x);
        if (x>=0)
        {
            if (x<pos)
            {
                pos=x;
            }            
        }
        else if (x<0)
        {
            neg=x;
            if (prox>neg)
            {
                
                prox=neg;
            }
            
        }
        
        controle+=1;
    }
    printf("maior valor negativo: %d\n", neg);
    printf("menor valor positivo: %d\n", pos);
    
    return 0;
}
