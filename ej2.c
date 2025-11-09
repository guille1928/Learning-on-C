#include<stdio.h>

//Ejercicio 2
//Apartado 1-------------------------------------------------
//Apartado1.1
//declaro la constante simbolica
#define SIZE 10
//Apartado1.2
//declaro la estructura
struct potencia_p {
int base;
int exp;
int potencia;
};
//Apartado1.3
//declaro puntero de la estructura
typedef struct potencia_p potenciaP_t;

//Apartado1.4
//creo funcion para recibir el puntero y los valores 
int setBaseExp (potenciaP_t *PPotencia, int baseF, int expF){
    PPotencia->base =baseF;
    PPotencia->exp =expF;
    PPotencia->potencia=-1;
return 0;
}
//Apartado1.5
//creo funcion para retornar la potencia 
int getPotencia (int baseF, int expF){
    int i =0;
    int potencia=1;
    while (i < expF ){
        potencia *= baseF;
        i++;
    }

    return potencia;
}

//Apartado1.6
//creo función 
void setPotenciaEst (potenciaP_t *PPotencia){
PPotencia->potencia=(getPotencia(PPotencia->base,PPotencia->exp));
}


int leer (potenciaP_t *p){
    printf("La base es %d : y el exp es %d : \n",p->base,p->exp);
    printf("La potencia es %d :  ", p->potencia);
    return 0;

}

//Apartado 2-------------------------------------------------
//Apartado 2.1
//creo funcion para iniciar el array que no devuelve nada
void initArrayEst (potenciaP_t  arr[]){
for (int i=0; i<SIZE;i++){
    arr[i].base =i+1;
    arr[i].exp=0;
    arr[i].potencia=1;
}
}

//se crea funcion que recibe un array de potencia_t y printa cada valor del array
void ComprobarArray(potenciaP_t arr[]){
printf(" Índice");
for (int i =0; i< SIZE; i++){
    printf(" i:%d ",i);
}
printf("\n");
printf(" base");
for (int i =0; i<SIZE; i++){
   printf(" %d ",arr[i].base );   
}
printf("\n");
printf(" exp");
for (int i =0; i<SIZE; i++){
    printf (" %d ",arr[i].exp );
}
printf("\n");
printf(" potencia");
for (int i =0; i<SIZE; i++){
    printf(" %d  ", arr[i].potencia);
}
printf("\n");

}

//creo array para printar el array 
void printArrayEst (potenciaP_t arr[]){

    
}

int main (){
potenciaP_t potencia;
potenciaP_t array[SIZE];
if(setBaseExp(&potencia,4,4)==0){
    printf("Creado correntamente \n");
    setPotenciaEst(&potencia);
    printf("Todo bien \n");
    leer(&potencia);
}

printf("\n Apartado 2 : \n");
printf("Inicio y compruebo como esta el array \n");
initArrayEst(array);
ComprobarArray(array);


}