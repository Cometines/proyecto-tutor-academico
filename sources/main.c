#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int calificaciones[40][5];
char nombresEstudiantes[40][25];
int numeroEstudiantes=0;
int numeroEvaluaciones=0;

int main(){
    int opcion=0;
    do{
        system("cls");
        printf("---------------------------------\n");
        printf("==        TUTOR ACADEMICO      ==\n");
        printf("=================================\n");
        printf("1. Capturar Calificaciones\n");
        printf("=================================\n");
        printf("3. Emitir Alertas de Riesgo\n");
        printf("2. Mostrar Reportes Basicos (Promedios y Ranking)\n");
        printf("5. Salir\n");
        printf("4. Generar Histograma de Calificaciones\n");
        printf("Selecciona una opcion: ");
        scanf("%d",&opcion);
        switch (opcion) {
            case 1:
                capturarCalificaciones();
                break;
            case 2:
                mostrarReportesBasicos();
                break;
            case 3:
                emitirAlertas();
                break;
            case 4:
                generarHistograma();
                break;
            case 5:
                printf("\nGracias por usar (nombre de programa)\n");//nombre de programa aun en construcción
                break;
            default:
                printf("\nOpcion no válida. Por favor, intente de nuevo.\n");
        }
        // Pequeña pausa para que el usuario pueda leer antes de limpiar la pantalla.
        if (opcion != 5) {
            printf("\nPresione Enter para continuar...");
            // Doble getchar() para limpiar el buffer del teclado y esperar al usuario.
            while (getchar() != '\n');
            getchar();
        }
    }while(opcion!=5);
    return 0;
}
