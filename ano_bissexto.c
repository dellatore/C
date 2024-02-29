#include <stdio.h>

int dataValida(int dia, int mes, int ano);
int eh_bissexto(int ano);
int main(int argc, char const *argv[])
{
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    int conta_1,conta_2;
    conta_1=dataValida(dia, mes, ano);
    conta_2=eh_bissexto(ano);
    printf("%d %d %d", dia, mes, ano);
    return 0;
}

int dataValida(int dia, int mes, int ano)
{
    int sla;
    sla=eh_bissexto(ano);
    if (sla==0 && mes==2)
    {
      if (dia>=1 && dia<=29)
      {
         return dia;
      }
    }
    else if (mes==2)
    {
       if (dia>=1 && dia<=28)
       {
        return dia;
       }else
       {
        return printf("numero invalido");
       }
       
    }
    else if (dia>=1 && dia<=31)
    {
        return dia;
    }
    else
    {
     return printf("numero invalido");
    }

    
    
    if (mes>=1 && mes<=12)
        {
            return mes;
        }else
        {
            return printf("numero invalido");
        }
     
        if (ano>=1900 && ano<=2200)
        {
            return ano;
        }
        else
        {
         return printf("numero invalido");
        }
          
}

int eh_bissexto(int ano)
{   if (ano%4==0)
    {
        return 0;
    }
    else{
        return 1;
    }
}
