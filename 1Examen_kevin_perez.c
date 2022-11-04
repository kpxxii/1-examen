//  PRIMERA EVALUACION PRACTICA
//Perez Muñoz Kevin Isaac     2CV3


#include <stdio.h>
#include <time.h>   //Para la funcion clock(), 
                    //constante CLOCKS_PER_SEC
                    //tipo de dato clock_t

#define TAMANIO 2000    //Definimos el tamanio de nuestro arreglo

//Prototipo de funciones
void ordenamientoBurbuja(int arreglo[]);
void ordenamientoXseleccion(int arreglo[]);
void ordenamientoXinserccion(int arreglo[]);

void imprimir_arreglo(const int *arreglo);
void copia_arreglo(int *arrayC, const int *arrayCopiado);


int main(){
    int a_desordenado[TAMANIO];
    //Requerimos tres nuevos arreglos ya que al implementar cada algoritmo de ordenamiento 
    //este arreglo sera modificado y ordenado. Dejandolo incervible para nuestro siguiente algoritmo de ordenmaiento.
    int a_burbuja[TAMANIO];
    int a_seleccion[TAMANIO];
    int a_inserccion[TAMANIO];
    
    double tiempo_burbuja = 0;      //Guardara el tiempo consumido por el algoritmo burbuja
    double tiempo_seleccion = 0;
    double tiempo_inserccion = 0;
    clock_t empieza;    //Comienza a contar
    clock_t termina;    //Termina de contar

    //Para ingresar los 2K numeros opte por utilizar el siguiente comando en consola
    //      archivo.exe < setdatosedades.txt
    //mas el siguiente for que ingresara todos los datos en el arreglo
    printf("Ingrese datos al arreglo: \n");
    for(int i=0; i<TAMANIO; i++){
        scanf("%d", &a_desordenado[i]);
    }

    //Realice la copia en los arreglos respectivos
    copia_arreglo(a_burbuja, a_desordenado);
    copia_arreglo(a_seleccion, a_desordenado);
    copia_arreglo(a_inserccion, a_desordenado);


    //Se hacen los ordenmaientos y tambien tomo el tiempo de ejecicion de cada uno
    empieza = clock();
    ordenamientoBurbuja(a_burbuja);
    termina = clock();
    tiempo_burbuja = (double)(termina-empieza) / CLOCKS_PER_SEC;

    empieza = clock();
    ordenamientoXseleccion(a_seleccion);
    termina = clock();
    tiempo_seleccion = (double)(termina-empieza) / CLOCKS_PER_SEC;

    empieza = clock();
    ordenamientoXinserccion(a_inserccion);
    termina = clock();
    tiempo_inserccion = (double)(termina-empieza) / CLOCKS_PER_SEC;


//Se muestran el arreglo ordenado
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tORDENAMIENTO BURBUJA:\n");
    imprimir_arreglo(a_burbuja);

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tORDENAMIENTO SELECCION:\n");
    imprimir_arreglo(a_seleccion);

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tORDENAMIENTO INSERCCION:\n");
    imprimir_arreglo(a_inserccion);

//Se muestran los resultados de los tiempos de ejecucion
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\tTiempo consumido por BURBUJA: %lf", tiempo_burbuja);
    printf("\n\t\tTiempo consumido por SELECCION: %lf", tiempo_seleccion);
    printf("\n\t\tTiempo consumido por INSERCCION: %lf", tiempo_inserccion);

    return 0;
}//Fin del main


//Definicion de Funciones 
void imprimir_arreglo(const int *arreglo){  //El arreglo es const para evitar que se modifique por error
    int i;

    printf("\n\tMostrar el arreglo: \n");
    for(i=0; i<TAMANIO; i++){
        printf("%d\t", arreglo[i]);
        if(i>0 && i%20==0)
            printf("\n");
    }
}//Fin de imprimir_arreglo


void copia_arreglo(int *arrayC, const int *arrayCopiado){
    int i;

    for(i=0; i<TAMANIO; i++){
        arrayC[i] = arrayCopiado[i];
    }
}//Fin de copia_arreglo


void ordenamientoBurbuja(int arreglo[]){
    int aux;
    int i, j;

    for(i=0; i<TAMANIO; i++){
        for(j=0; j<TAMANIO-1; j++){
                if(arreglo[j]>arreglo[j+1]){
                    aux=arreglo[j+1];
                    arreglo[j+1] = arreglo[j];
                    arreglo[j] = aux;
                }
            }
    }
}//Fin de ordenamientoBurbuja


void ordenamientoXseleccion(int arreglo[]){
    int mayor;
    int i,j;

//Bucle para ubicar y mover el indice del arreglo
    for(i=0; i<TAMANIO; i++){
        //Bucle para buscar el menor
        for(j=i+1; j<TAMANIO; j++){
            if(arreglo[j] < arreglo[i]){
                    mayor = arreglo[i];
                    arreglo[i] = arreglo[j];
                    arreglo[j] = mayor;
                }
        }
    }
}//Fin de ordenamientoXseleccion


void ordenamientoXinserccion(int arreglo[]){
    int actual;
    int aux;
    int i;

    for(i=0; i<TAMANIO; i++){
        actual = i;
        aux = arreglo[i];
        //Se desplazara hacia la izquierda buscando al menor
        while((actual>0) && (arreglo[actual-1] > aux)){
            arreglo[actual] = arreglo[actual-1];
            actual--;
        }
        arreglo[actual] = aux;
    }

}//Fin de ordenamientoXinserccion



