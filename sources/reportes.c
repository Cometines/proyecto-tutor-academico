#include <stdio.h>
#include <string.h>
#include "../headers/reportes.h"

void calcularPromedioEstudiante(){
    int promedio=0;
    printf("\nPROMEDIOS GENERALES DE LOS ESTUDIANTES DURANTE SUS %d EVALUACIONES", numeroEvaluaciones);
    for(int i=0;i<numeroEstudiantes;i++){//El ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
        for(int j=0;j<numeroEvaluaciones;j++){//El ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
            promedio+=calificaciones[i][j];//Sumamos las calificaciones de cada alumno en todas sus evaluaciones
        }
        promedio/=numeroEvaluaciones;//Se divide la suma de sus calificaciones en todas sus evaluaciones entre el numero de evaluaciones
        printf("\nEstudiante %d: %d", (i+1),promedio);
    }
}
void calcularPromedioEvaluacion(){
    int promedio=0;
    printf("\nPromedio generales del grupo en las evaluaciones");
    for(int j=0;j<numeroEvaluaciones;j++){//El ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
        for(int i=0;i<numeroEstudiantes;i++){//El ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
            promedio+=calificaciones[i][j];//Sumamos todas las calificaciones del grupo en la evaluacion en curso del ciclo
        }
        promedio/=numeroEstudiantes;//Se divide la suma de todas las calificaciones del grupo en esa evaluacion entre el tamaño del grupo(el numero de estudiantes)
        printf("Promedio general del grupo en la evaluación %d: %d",(j+1),promedio);
    }
}
void generarRanking(){
    // 1. Definimos el struct.
    // Esta struct solo existe dentro de esta función.
    struct EstudianteRanking {
        char nombre[50];
        float promedio;
    };
    // 2. Creamos un arreglo de estas "cajas",
    // una por cada estudiante.
    struct EstudianteRanking ranking[numeroEstudiantes];
    // 3. Llenamos el arreglo de ranking
    for (int i = 0; i < numeroEstudiantes; i++) {
        // Calculamos el promedio para el estudiante 'i'
        float prom = 0.0;
        for (int j = 0; j < numeroEvaluaciones; j++) {
            prom += calificaciones[i][j];
        }
        prom /= numeroEvaluaciones;
        // Guardamos los datos JUNTOS en la "caja"
        ranking[i].promedio = prom;
        strcpy(ranking[i].nombre, nombresEstudiantes[i]);
    }
    // 4. Ordenamos el arreglo de "cajas" (Método Burbuja Descendente)
    // Comparamos los promedios, pero intercambiamos LA CAJA ENTERA.
    for (int i = 0; i < numeroEstudiantes - 1; i++) {
        for (int j = 0; j < numeroEstudiantes - i - 1; j++) {
            // Comparamos promedios
            if (ranking[j].promedio < ranking[j + 1].promedio) {
                // Intercambiamos la "caja" completa
                struct EstudianteRanking temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }
    // 5. Mostramos el Top 3
    printf("\n--- Ranking (Top 3) ---\n");
    // Nos aseguramos de no intentar mostrar 3 si hay menos de 3 estudiantes
    int topN = (numeroEstudiantes < 3) ? numeroEstudiantes : 3;
    //si el numero de estudiantes es menor a 3 topN=numeroEstudiantes, si no, topN=3
    for (int i = 0; i < topN; i++) {
        printf("%d. %s - Promedio: %.2f\n", i + 1, ranking[i].nombre, ranking[i].promedio);
    }
}