#include <stdio.h>

int main()
{
    int x,y,controle,controle2;
    scanf("%d", &x);
    y=1;
    controle=0;
    controle2=0;
    while(y<x)
    {
        if (x%y==0)
        {
            controle+=y;
        }
        y++;
    }
    y=1;
    while (y<controle)
    {
        if (controle % y==0)
        {
            controle2+=y;
        }
        y++;
    }
    if (controle2==x)
    {
        printf("numero amigavel:%d", controle);
    }else
    {
        printf("o numero %d nao possui amigavel", x);
    }
    
    
    return 0;
}
