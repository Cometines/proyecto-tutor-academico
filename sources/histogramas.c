// Importación de librerias para la correcta función de la librería
#include <stdio.h>
#include <stddef.h>
#include <Windows.h> 
#include "../headers/histogramas.h"

short int rangos[5] = {0}; // Variable que fungirá como indicador de rangos dependiendo la posición(0-59, 60-69, 70-79...)

// static void calcularPromedios(int calificaciones[40][5], int estudiantes, int evaluaciones){
//     int promedio = 0;
//     for(size_t f = 0; f <= estudiantes; f++){
//         for(size_t c = 0; c <= evaluaciones; c++){
//             promedio += calificaciones[f][c];
//         }
//         promedio /= evaluaciones;
//         asignarPosicion(promedio);
//     }
// }

static void asignarPosicion(float promedio){
    short int r1 = 0, r2 = 59; // Variables necesarias para ir asignando el rango.
    for(size_t i = 0; i < 5; i++){// Ciclo for para ir recorriendo el vector rangos
        if(promedio >= r1 && promedio <= r2){// Preguntamos si el valor que presente la variable promedio está dentro de un rango delimitado empezando de 0 a 59.
            rangos[i]++;//Si un promedio se encuentra dentro del rango, la posición en la que se encuentre el vector (que a su vez representa un rango) acumulará +1 unidad (representando la cantidad de promedios en respectivo rango)
            break;//Salimos del for para evitar recorrer todo el vector rangos si este ya encontró un rango.
        }
        else{//En caso de que el promedio no se encuentre dentro de un rango, se actualizarán los rangos a comparar en la proxima iteración.
            r1 = r2+1;
            r2 += 10;
        }
    }
}

static void mostrarHistograma(int estudiantes){
    size_t j;
    int porcentaje = 0;
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", rangos[i]); //Imprime la cantidad de promedios que hay en el rango correspondiente.
        porcentaje = ((rangos[i]*100)/estudiantes); //Calcula el porcenje respecto a la cantidad de promedios existentes
        j = 0;
        while (j <= porcentaje) //La cantidad de guiones que se generarán respecto al porcentaje.
        {
            printf("-"); //Simula una barra.
            Sleep(25); //"Dormimos" al sistema para crear una animación pequeña de generación del histograma.
        }
        printf(" %.2f%%", porcentaje); // Imprimimos el porcentaje que le corresponde a un rango.
    }
}

void iniciarHistograma(int Estudiantes, int Evaluaciones){

    for (size_t i = 0; i < 40; i++)
    {
        asignarPosicion(promedioEstudiantes[i]);
    }
    mostrarHistograma(Estudiantes);
}