#include <stdio.h>
#include <string.h> 
#include "../headers/captura.h"

int capturarNumeroEstudiantes(){
    int numeroEstudiantes = 0; 
    int i = 1;
    do{
        printf("\n--- Captura de Datos ---\n");
        printf("Cuantos estudiantes son? (1-40): ");
        scanf("%d", &numeroEstudiantes);
        if (numeroEstudiantes > 40 || numeroEstudiantes < 1)
            printf("RANGO ESTABLECIDO: 1-40. VUELVA A INTENTARLO");
        else
            i = 0;
    }while(i!=0);
    return numeroEstudiantes;
}

int capturarNumeroEvaluaciones(){
    int numeroEvaluaciones=0;
    int i = 1;
    do
    {
        printf("Cuantas evaluaciones son? (1-5): ");
        scanf("%d", &numeroEvaluaciones);
    
        if (numeroEvaluaciones > 0 && numeroEvaluaciones < 6)
            i = 0;
        else
            printf("RANGO ESTABLECIDO: 1-5. VUELVA A INTENTARLO");
        // TODO: Añadir validaciones para que los números estén en el rango correcto.
    } while (i!=0);

    return numeroEvaluaciones;
}
void capturarCalificaciones(int numeroEstudiantes, int numeroEvaluaciones){
    printf("\nAhora, ingrese los datos de cada estudiante:\n");
    while (getchar() != '\n');
    for (int i = 0; i < numeroEstudiantes; i++) {
        printf("\nNombre del Estudiante %d: ", i + 1);
        // scanf(" [^\n]", nombresEstudiantes[i]); // Lee nombres con espacios
        fgets(nombresEstudiantes[i], 50, stdin);
        nombresEstudiantes[i][strcspn(nombresEstudiantes[i], "\n")] = '\0';

        for (int j = 0; j < numeroEvaluaciones; j++) {
            printf("  Ingrese calificacion de la Evaluacion %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
            // TODO: Añadir validación para que la nota esté entre 0 y 100.
        }
        while (getchar() != '\n');
    }
    printf("\n[!] Datos guardados correctamente.\n");
}
void calcularPromedioEstudiante(int num_estudiantes, int num_evaluaciones){
    float promedio;
    for(size_t i=0;i<num_estudiantes;i++){//El ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
        promedio=0.0;
        for(size_t j=0;j<num_evaluaciones;j++){//El ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
            promedio+=calificaciones[i][j];//Sumamos las calificaciones de cada alumno en todas sus evaluaciones
        }
        promedio/=num_evaluaciones;//Se divide la suma de sus calificaciones en todas sus evaluaciones entre el numero de evaluaciones
        promediosEstudiantes[i]=promedio;
    }
}