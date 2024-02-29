#include <stdio.h>

int eh_primo(int number);

int main()
{
   int number,total;
   number=1;
   while (number<=999999)
   {
        if (eh_primo(number))
        {
            total++;
            
        }
    
     number++;
   }
    printf("%d\n", total); 
    return 0;
}

int eh_primo(int number)
{
    int denominador,primo;
    denominador=1;
    primo=0;
    while (denominador<=number)
    {
       if (number % denominador==0)
       {
          primo++;
       }
       denominador++;
    }
    if (primo==2)
    {
        return 1;
    }else
    {
        return 0;
    }
    
    
}

