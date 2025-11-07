#include <stdio.h>
#include <stddef.h>
#include <Windows.h> 
#include "../headers/histogramas.h"

short int rangos[5] = {0};

static void asignarPosicion(float promedio){
    short int r1 = 0, r2 = 59;
    for(size_t i = 0; i < 5; i++){
        if(promedio >= r1 && promedio <= r2){
            rangos[i]++;
            break;
        }
        else{
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
        printf("%d ", rangos[i]);
        porcentaje = ((rangos[i]*100)/estudiantes);
        j = 0;
        while (j <= porcentaje)
        {
            printf("-");
            Sleep(25);
        }
        printf(" %.2f%%", porcentaje);
    }
    
}

void iniciarHistograma(int Estudiantes, int Evaluaciones){

    for (size_t i = 0; i < 40; i++)
    {
        asignarPosicion(promediosEstudiantes[i]);
    }
    mostrarHistograma(Estudiantes);
}