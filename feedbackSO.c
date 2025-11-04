#include<stdio.h>

//Apartado 1
//----------------------------------------------------------
//declaro la estructura
struct arrayLength {
    int arrInt[10];
    int arrSize;
    int arrAdd;

};
//creo el alias
typedef struct arrayLength arrayLength_t;

//Apartado 2
//----------------------------------------------------------
//funcion para pasarle un puntero y add los valores -1 al array
int initArray(arrayLength_t *pArray){

if (pArray ==NULL){
    return -1;
}

pArray->arrSize=0;
pArray->arrAdd=0;
//recorremos el array para rellenarlo
for (int i =0; i<10; i++){
  pArray->arrInt[i]=-1;
}

return 0;
}
//funcion printArr para mostrar los valores del array con un for 
int printArr(arrayLength_t *pArray){
    printf("{ [");
    for(int i =0; i<10;i++){
        printf("%d ",pArray->arrInt[i]);
        if (i<9){
            printf(", ");}
    }
    printf("], %d, %d}\n",pArray->arrSize,pArray->arrAdd);
    return 0;
}
//funcion para meter nuevos valores al array
int addElement (arrayLength_t *pArray, int n){
//si es negativo o nulo retorno -1
if(n<0 || pArray== NULL){
    return -1;
}
    //compruebo si n es positivo y hay hueco lo añado y actualizo size y la suma
    if (n >0 && pArray->arrSize<10){
        pArray->arrInt[pArray->arrSize]=n;
        pArray->arrSize+=1;
        pArray->arrAdd+=n;
    }else {return -1;}
return 0;

}


//Apartado 3
//----------------------------------------------------------
int getArrSize (arrayLength_t *pArray){
if (pArray== NULL){
    return -1;
}
//devuelvo el size del array
return pArray->arrSize; 
}

int getElement (arrayLength_t *pArray, int n){
if (pArray== NULL){
    return -1;
}
//compruebo si n es mayor o igual a cero y está dentro del length del array
if(n>=0 && n<pArray->arrSize){
return pArray->arrInt[n];
}else {return -1; }

}
//Apartado 4
//----------------------------------------------------------


int main (){
arrayLength_t miArray;

if(initArray(&miArray) == 0){
    printf("Ha salido todo bien \n");
}else {printf("Error de inicialización");}
printArr(&miArray);
//meto 2 valores nuevos
printf("Se meten nuevos valores  \n");
if(addElement(&miArray,22)==0){
    printf("Valor metido correctamente \n");
printArr(&miArray);
}else {printf("Hubo un error al añadir el valor");}
if(addElement(&miArray,44)==0){
    printf("Valor metido correctamente \n");
printArr(&miArray);
}else {printf("Hubo un error al añadir el valor");}
//retorno el size nuevo del array
printf (" El numero de elementos del array es : %d\n",getArrSize(&miArray));
printf("\n");
//retorno el valor de la posicion del array pasada a la funcion
int num=0;
printf("La posicion %d tiene el valor : %d \n" , num,getElement(&miArray,num));
}