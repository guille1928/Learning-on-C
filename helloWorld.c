#include <stdio.h>

int main(){
int i=0;
printf("Conocido \n la i es = %d",i ,"\n");

printf("Creando un puntero\n");

char a[]="Hola se bienvenido al array";
char *c;
c=a;
int b= 34;
int *p;

printf("El mensaje del array dice : '%s'" ,c);
p=&b;
printf("\n Ahora el puntero p tiene el valor de b = %d" ,*p );
b= 22;
printf("\n Ahora el puntero p tiene el valor de b = %d" ,*p );
return 0;

}

