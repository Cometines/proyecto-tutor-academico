#include <stdio.h>
#include <stdbool.h>
#include "../headers/alertas.h" //Subir para encontrar al arichivo
void emitirAlertas(){
    float prom=0;// Variable que guarda la sumatoria de los promedios de un alumno
    int filas,columnas;
    bool noHayAlertas=true;//Variable para determinar si no existe ni una alerta de reprobado
    for(filas=0;filas<numeroEstudiantes;filas++){//Cambia al siguiente alumno despues de calcular el promedio
        prom=0;
        for(columnas=0;columnas<numeroEvaluaciones;columnas++){//Cambia de columna(promedio) para lograr calcular el promedio final de cada alumnno
            prom+=calificaciones[filas][columnas];//Sumatoria de todos los promedios de un alumno
        }
        if((prom/numeroEvaluaciones)<=70 ){//Calculo del promedio y aloración de si el alumno esta en riesgo
                noHayAlertas=false;//Si existe minimo una alerta, se vuelve falsa la variable
                printf("El alumno:  %s, esta en riesgo con un promedio de %.2f\n",nombresEstudiantes[filas],(prom/numeroEvaluaciones));
            }
    }
    if(noHayAlertas){
        printf("No hay alumnos en riesgo\n");
    }   
}