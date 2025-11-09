#include<stdio.h>

//Ejercicio 2
//Apartado 1-------------------------------------------------
//Apartado1.1
//declaro la constante simbolica
#define SIZE = 10;
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

int main (){
potenciaP_t potencia;
if(setBaseExp(&potencia,4,4)==0){
    printf("Creado correntamente \n");
    setPotenciaEst(&potencia);
    printf("Todo bene \n");
    leer(&potencia);
}


}