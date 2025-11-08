#include <stdio.h>
#include <stdlib.h>
#include "../headers/modificar.h"
#include "../headers/reportes.h"
#include "../headers/numeros.h"
#include "../headers/plataforma.h"

// --- Función Privada de Recálculo ---
// Esta función recalcula el promedio para UN SOLO estudiante
// No necesita estar en el .h porque solo la usa este archivo
void recalcularPromedio(int indiceEstudiante, int numeroEvaluaciones) {
    float suma = 0.0;
    for (int j = 0; j < numeroEvaluaciones; j++) {
        suma += calificaciones[indiceEstudiante][j];
    }
    promediosEstudiantes[indiceEstudiante] = suma / (float)numeroEvaluaciones;
    printf("\n[!] Promedio recalculado y actualizado: %.2f\n", promediosEstudiantes[indiceEstudiante]);
}
// --- Función Pública del Submenú ---
void gestionarModificaciones(int numeroEstudiantes, int numeroEvaluaciones) {
    int opcionMod = 0;
    do {
        limpiarConsola();
        printf("--- Submenu de Modificaciones ---\n");
        mostrarListaPromedios(numeroEstudiantes,numeroEvaluaciones);
        printf("--- Opciones de modificación ---\n");
        printf("1. Modificar Nombre de Estudiante\n");
        printf("2. Modificar Calificacion\n");
        printf("3. Volver al Menu Principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        opcionMod = getInt();

        int indiceEst, indiceEv; // Índices para el estudiante y la evaluación

        switch(opcionMod) {
            case 1: // --- Modificar Nombre ---
                printf("Ingrese el No. de lista del estudiante (1 a %d): ", numeroEstudiantes);
                indiceEst = getInt();
                indiceEst--; // Convertir de No. de lista (1-based) a índice (0-based)

                if (indiceEst < 0 || indiceEst >= numeroEstudiantes) {
                    printf("Error: Numero de lista invalido.\n");
                } else {
                    printf("Nombre actual: %s\n", nombresEstudiantes[indiceEst]);
                    printf("Ingrese el nuevo nombre: ");
                    scanf(" %[^\n]", nombresEstudiantes[indiceEst]);
                    printf("Nombre actualizado exitosamente.\n");
                }
                break;
            
            case 2: // --- Modificar Calificación ---
                printf("Ingrese el No. de lista del estudiante (1 a %d): ", numeroEstudiantes);
                indiceEst = getInt();
                indiceEst--; // Convertir a 0-based

                if (indiceEst < 0 || indiceEst >= numeroEstudiantes) {
                    printf("Error: Numero de lista invalido.\n");
                    break; // Salir de este 'case'
                }

                printf("Modificando a: %s\n", nombresEstudiantes[indiceEst]);
                printf("Ingrese el No. de evaluacion a modificar (1 a %d): ", numeroEvaluaciones);
                indiceEv = getInt();
                indiceEv--; // Convertir a 0-based

                if (indiceEv < 0 || indiceEv >= numeroEvaluaciones) {
                    printf("Error: Numero de evaluacion invalido.\n");
                    break; // Salir de este 'case'
                }

                printf("Calificacion actual (Ev. %d): %.2f\n",indiceEv + 1,calificaciones[indiceEst][indiceEv]);
                int b = 0;
                do
                {
                    printf("Ingrese la nueva calificacion (0-100): ");
                    calificaciones[indiceEst][indiceEv] = getFloat();
                    if (calificaciones[indiceEst][indiceEv] < 0 || calificaciones[indiceEst][indiceEv] > 100)
                        printf("Por favor, ingresa una calificación dentro del rango especificado.");
                    else
                        b = 1;
                } while (b!=1);
                // ... (agregar validación 0-100) ...

                // --- Recalcular Promedio (Petición clave) ---
                recalcularPromedio(indiceEst,numeroEvaluaciones);
                
                break;

            case 3:
                printf("Volviendo al menu principal...\n");
                break;

            default:
                printf("Opcion de sub-menu no valida.\n");
        }
        
        if (opcionMod != 3) {
            printf("\nPresione Enter para continuar en el sub-menu...");
            while (getchar() != '\n');
            getchar();
        }

    } while(opcionMod != 3);
}