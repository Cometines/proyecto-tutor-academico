#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "headers/captura.h"
#include "headers/reportes.h"
#include "headers/alertas.h"
#include "headers/histogramas.h"
#include "headers/modificar.h"

/*Integrantes del equipo:
Méndez Lagunes Leonardo Alberto
Feliciano González Ervin Antonio
Sánchez Trujillo Emmanuel
García Gómez Olga Lisseth
Reyes Torres Kelaia
*/

int calificaciones[40][5];
char nombresEstudiantes[40][50];
float promediosEstudiantes[40];
int numeroEstudiantes=0;
int numeroEvaluaciones=0;

int main() {
    // Se ejecutará infinitamente hasta que se cierre la consola.
    do {
        system("cls");
        printf("==================================================\n");
        printf("==      BIENVENIDO AL SISTEMA TUTOR ACADEMICO   ==\n");
        printf("==   Se requiere la captura inicial de datos    ==\n");
        printf("==================================================\n");

        // --- 1. CAPTURA DE DATOS FORZADA ---
        numeroEstudiantes=capturarNumeroEstudiantes();
        numeroEvaluaciones=capturarNumeroEvaluaciones();
        capturarCalificaciones(numeroEstudiantes,numeroEvaluaciones); // Llena 'nombresEstudiantes' y 'calificaciones'
        calcularPromedioEstudiante(numeroEstudiantes,numeroEvaluaciones); // Llena 'promediosEstudiantes'

        printf("\n¡Datos capturados y promedios calculados!\n");
        printf("Presione Enter para acceder al menu principal...");
        while (getchar() != '\n');
        getchar();

        // --- 2. BUCLE INTERNO (MENÚ PRINCIPAL) ---
        int opcionMenu = 0;
        do {
            system("cls");
            printf("---------------------------------\n");
            printf("==        TUTOR ACADEMICO      ==\n");
            printf("==        MENU  PRINCIPAL      ==\n");
            printf("=================================\n");
            printf("1. Mostrar Reportes Basicos\n");
            printf("2. Mostrar Alertas de Riesgo\n");
            printf("3. Generar Histograma\n");
            printf("4. Modificar datos de un alumno\n");
            printf("5. Reiniciar programa (Ingresar nuevos datos)\n");
            printf("---------------------------------\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcionMenu);

            switch (opcionMenu) {
                case 1:
                    mostrarReportes(numeroEstudiantes,numeroEvaluaciones); // De reportes.c
                    break;
                case 2:
                    emitirAlertas(); // De alertas.c
                    break;
                case 3:
                    iniciarHistograma(numeroEstudiantes,numeroEvaluaciones); // De histograma.c
                    break;
                case 4:
                    gestionarModificaciones(numeroEstudiantes,numeroEvaluaciones); // De modificar.c
                    break;
                case 5:
                    printf("\nReiniciando el programa...\n");
                    // Al salir de este bucle, el bucle externo se repetirá, forzando la captura de datos de nuevo.
                    printf("Presione Enter para confirmar...");
                    while (getchar() != '\n');
                    getchar();
                    break;
                default:
                    printf("\nOpcion no valida. Intente de nuevo.\n");
            }

            // Pausa solo para las opciones 1-4
            if (opcionMenu > 0 && opcionMenu < 5) {
                printf("\nPresione Enter para volver al menu...");
                while (getchar() != '\n');
                getchar();
            }

        } while (opcionMenu != 5); // El bucle del menú termina cuando el usuario elige 5

    } while (true); // Siempre se repite, forzando el reinicio

    return 0; // (Este código ya no es alcanzable, pero es estándar)
}
