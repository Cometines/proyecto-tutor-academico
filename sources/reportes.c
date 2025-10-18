#include <stdio.h>
#include "../headers/reportes.h"

void calcularPromedioEstudiante(){
    int promedio=0;
    printf("\nPROMEDIOS GENERALES DE LOS ESTUDIANTES DURANTE SUS %d EVALUACIONES", numeroEvaluaciones);
    for(int i=0;i<numeroEstudiantes;i++){//el ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
        for(int j=0;j<numeroEvaluaciones;j++){//el ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
            promedio+=calificaciones[i][j];//sumamos las calificaciones de cada alumno en todas sus evaluaciones
        }
        promedio/=numeroEvaluaciones;//se divide la suma de sus calificaciones en todas sus evaluaciones entre el numero de evaluaciones
        printf("\nEstudiante %d: %d", (i+1),promedio);
    }
}
void calcularPromedioEvaluacion(){
    int promedio=0;
    printf("\nPromedio generales del grupo en las evaluaciones");
    for(int j=0;j<numeroEvaluaciones;j++){//el ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
        for(int i=0;i<numeroEstudiantes;i++){//el ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
            promedio+=calificaciones[i][j];//sumamos todas las calificaciones del grupo en la evaluacion en curso del ciclo
        }
        promedio/=numeroEstudiantes;//se divide la suma de todas las calificaciones del grupo en esa evaluacion entre el tamaño del grupo(el numero de estudiantes)
        printf("Promedio general del grupo en la evaluación %d: %d",(j+1),promedio);
    }
}