#include <stdio.h>

int max(int a, int b, int c);


int main(int argc, char const *argv[])
{
    int a,b,c,d,e,f,g,h,i,j;
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    int conta;
    conta= max(max(max(max(max(a,b,c),d,e),f,g),h,i),j,j);
    printf("%d", conta);
    return 0;
}

int max(int a, int b, int c)
{
   if (a>b && a>c)
   {
    return a;
   }
   if (b>a && b>c)
   {
    return b;
   }
   else
   {
    return c;
   }

}