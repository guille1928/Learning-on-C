//Autor Guillermo Fernandez Tardon NP174292
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>


/*Para levantar Ubuntu en WSL windows:
Terminal :
wsl
Si no esta levantado 
wsl --list --verbose
wsl -d Ubuntu

Ir al directorio :
gcc ej2.c -o ej2  compilo y cargo el archivo 
./ej2

*/

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

//Apartado 2.2
//creo array para printar el array según el apartado
void printArrayEst (potenciaP_t arr[]){
for (int i=0;i<SIZE;i++){
printf("arr[%d] : base: %d exp: %d potencia %d \n" , i,arr[i].base,arr[i].exp,arr[i].potencia);
}
}

//Apartado 2.3
//función para crear hebras
void* calcuPotHeb (*void arg){
potenciaP_t *p= (potenciaP_t*) arg;
setPotenciaEst(p);
return arg;

}


//Apartado 3 
//Funciones extras
void modifyArray (potenciaP_t array[], int base , int exp){
    for (int i=0;i<SIZE; i++){
      setBaseExp(&array[i],i+1,2);
    }
}

//Apartado 3.6
//funcion para crear hijos con funcion fork
void crearHijosCalculo (potenciaP_t arr[], int size){
    pid_t pid;
    for (int i =0; i< size;i++){
        pid=fork();
        if(pid<0){
            printf("Error al crear el proceso hijo");
            return;
        }else if (pid == 0){
            //proceso hijo
            int resultado = getPotencia(arr[i].base,arr[i].exp);
            exit(resultado %255);
        }
    }
//proceso padre
int status;
for(int i =0; i<size;i++){
    pid_t hijoTerminado = wait(&status);
    if (WIFEXITED(status)) {
            int valor = WEXITSTATUS(status);
            arr[i].potencia = valor;
        }
}
}

//Apartado 3.13
void sizeHebras (potenciaP_t array[]){
pthread_t hilos[SIZE];
for(int i=0;i<SIZE;i++){
    //Cuando la hebra empiece a ejecutarse, ejecuta esta función CalcuPotHeb
pthread_create (&hilos[i],NULL,calcuPotHeb,&array[i]);
}
    //esperamos a que una hebra termine antes de continuar el progama principal
for(int i=0;i<SIZE;i++){
    pthread_join(hilos[i],NULL);
}
printf("\n Resultado de 'arr2' después de las hebras :\n");
printArrayEst(array);

}

int main (){
//creo objetos y arrays necesarios
potenciaP_t potencia;
potenciaP_t arrayTest[SIZE];
pid_t pids[SIZE];

if(setBaseExp(&potencia,4,4)==0){
    printf("Creado correntamente \n");
    setPotenciaEst(&potencia);
    printf("\n");
}

printf("\n Apartado 2 : \n \n");
printf("Inicio y compruebo como esta el array \n");
initArrayEst(arrayTest);
ComprobarArray(arrayTest);
printf("\n");
printf("Apartado 2.2 \n \n");
printArrayEst(arrayTest);

//Apartado 3-----------------------------------------------
//Apartado 3.1
printf("\n \n Apartado 3 : \n \n");
potenciaP_t arr1[SIZE];
//Apartado 3.2
initArrayEst(arr1);
printf("\nApartado 3.3 : \n \n");
//Apartado 3.3
printArrayEst(arr1);
printf("\n Apartado 3.4  y 3.5 :\n");
//Apartado 3.4
modifyArray(arr1,1,2);
printf("\n");
//Apartado 3.5
printArrayEst(arr1);

printf("\nApartado 3.6 y 3.7 :\n");
crearHijosCalculo(arr1,10);
printArrayEst(arr1);
printf("\nApartado 3.8 , 3.9 y 3.10  :\n");
potenciaP_t arr2[SIZE];
//Apartado 3.9
initArrayEst(arr2);
//Apartado 3.11
printArrayEst(arr2);
printf("\n");
modifyArray(arr2,1,2);
//Apartado 3.12 3.13 y 3.14
printArrayEst(arr2);
printf("\n");
sizeHebras(arr2);
}