// Importación de librerias para la correcta función de la librería
#include <stdio.h>
#include <stddef.h>
#include <Windows.h> 
#include "../headers/histogramas.h"

short int rangos[5] = {0}; // Variable que fungirá como indicador de rangos dependiendo la posición(0-59, 60-69, 70-79...)

void asignarPosicion(float promedio){
    int r1 = 0, r2 = 59; // Variables necesarias para ir asignando el rango.
    for(size_t i = 0; i < 5; i++){// Ciclo for para ir recorriendo el vector rangos
        if(promedio >= r1 && promedio <= r2+1){// Preguntamos si el valor que presente la variable promedio está dentro de un rango delimitado empezando de 0 a 59.
            rangos[i]++;//Si un promedio se encuentra dentro del rango, la posición en la que se encuentre el vector (que a su vez representa un rango) acumulará +1 unidad (representando la cantidad de promedios en respectivo rango)
            break;//Salimos del for para evitar recorrer todo el vector rangos si este ya encontró un rango.
        }
        else{//En caso de que el promedio no se encuentre dentro de un rango, se actualizarán los rangos a comparar en la proxima iteración.
            r1 = r2+1;
            r2 += 10;
        }
    }
}

void mostrarHistograma(int estudiantes/*Cantidad de estudiantes*/){
    size_t j; // Variable tipo size_t para el manejo de los arrays
    int r1 = 0, r2 = 59; //Variables necesarias para ir asignando el rango.
    float porcentaje = 0.0; //Variable que almacenará un porcentaje.
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d - %d ", r1, r2); //Imprime la cantidad de promedios que hay en el rango correspondiente.
        porcentaje = (float)((rangos[i]*100)/estudiantes); //Calcula el porcenje respecto a la cantidad de promedios existentes
        j = 0;
        while (j <= porcentaje) //La cantidad de guiones que se generarán respecto al porcentaje.
        {
            printf("-"); //Simula una barra.
            Sleep(15); //"Dormimos" al sistema para crear una animación pequeña de generación del histograma.
            j++; //Incremento del contador
        }
        printf(" %.2f%% (%d)\n", porcentaje, rangos[i]); // Imprimimos el porcentaje que le corresponde a un rango.
        if (i<3)
        {
            r1 = r2+1;
            r2 += 10;
        }
        else{
            r1 = r2+1;
            r2 += 11;
        }
    }
}

void iniciarHistograma(int Estudiantes){
    for (size_t i = 0; i < Estudiantes; i++)//El bucle iterará "Estudiantes" veces
    {
        asignarPosicion(promedioEstudiantes[i]);//Se llama a la funcion y le mandamos el valor de la variable extern promedioEstudiantes[posicion i]
    }
    mostrarHistograma(Estudiantes);//Se llama a la función y recibirá como parametro el valor de una variable del main.
}