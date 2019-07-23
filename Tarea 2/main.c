 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void revisa(char *m);
int numero(char *prt, int n);
int minuscula(char *prt, int n);
int main() {
    char c, *prt;
    int i=0;
    prt = (char *) malloc(1 * sizeof(char));
    *prt = '\0';
    while ((c=getch())!='\r'){
        printf("%c",'*');
        prt = (char*) realloc(prt, (i+2)*sizeof(char));
        prt[i++] = c;
        prt[i]='\0';
    }

    printf("\n");
    revisa(prt);

    return 0;
}
int numero(char *prt, int n)
{int i;
    for(i=0;i<n;i++)
    {
        if(prt[i]<=9 || prt[i]>=0 )
        {
            return 1;
        }
    }
    return 0;
}
int minuscula(char *prt, int n)
{int i;
    for(i=0;i<n;i++)
    {
        if(prt[i]>=97 && prt[i]<=122)
        {
            return 1;
        }
    }
    return 0;
}
void revisa(char *m)
{
    int p;
    p=strlen(m);
    if((p<20 && p>10 )&& (minuscula(m,p)==1)&&(numero(m,p)==1))
    {
        printf("La contraseña contiene todos los requisitos\n");
    }
    else
    {
        printf("La contraseña esta debil\n");
    }
}
