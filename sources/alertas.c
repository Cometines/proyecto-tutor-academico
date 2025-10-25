#include <stdio.h>
#include "../headers/alertas.h" //Subir para encontrar al arichivo
void emitirAlertas(){
    float prom;
    int filas,columnas;
    for(filas=0;filas<numeroEstudiantes;filas++){
        for(columnas=0;columnas<numeroEvaluaciones;columnas++){
            prom+=calificaciones[filas][columnas];
        }
        if((prom/numeroEvaluaciones)<=70){
                printf("El alumno:  %s, esta en riesgo con un promedio de %.2f\n",nombresEstudiantes[filas],(prom/numeroEvaluaciones));
            }
    }
}
