#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float calificaciones[40][5];
int numeroEstudiantes=0;
int numeroEvaluaciones=0;

void mostrarMenu();
void capturarCalificaciones();
void mostrarReportesBasicos();//a partir de esta función se llamarán a otras funciones mas pequeñas, que realizarán los diferentes reportes (divide y vencerás)
    void calcularPromediosEstudiante();
    void calcularPromediosEvaluacion();
    void generarRanking();
    void mostrarPeorCalificacion();
void emitirAlertas();
void generarHistograma();

int main(){
    int opcion=0;
    do{
        mostrarMenu();
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
/*
                IMPLEMENTACIÓN DE FUNCIONES
        Aqui irán las funciones correspondientes a cada
        opción del menú. División de tareas:
        capturarCalificaciones() -> Emma y Liss
        mostrarReportesBasicos() -> Leonardo
        emitirAlertas() -> Ervin
        generarHistogramas() -> Kelaia
*/
void mostrarMenu(){
    system("cls");
    printf("=================================\n");
    printf("==        TUTOR ACADEMICO      ==\n");
    printf("=================================\n");
    printf("1. Capturar Calificaciones\n");
    printf("2. Mostrar Reportes Basicos (Promedios y Ranking)\n");
    printf("3. Emitir Alertas de Riesgo\n");
    printf("4. Generar Histograma de Calificaciones\n");
    printf("5. Salir\n");
    printf("---------------------------------\n");
}
void capturarCalificaciones(){
    printf("\n[!] Funcion para CAPTURAR CALIFICACIONES en construcción");
}
void mostrarReportesBasicos(){
    printf("=================================\n");
    printf("==       REPORTES BASICOS      ==\n");
    printf("=================================\n");
    if(numeroEstudiantes==0){
        printf("\n[!] No se han capturado calificaciones aun. Ingrese calificaciones primero.");
        return; //usamos return aqui para que se termine el trabajo de esta función aqui y no realice lo demás
    }
    //Función que calcula los promedios por estudiante
    calcularPromediosEstudiante();
    //Función que calcula los promedios por evaluación
    calcularPromediosEvaluacion();
    //Función que genera el ranking de los 3 mejores promedios
    generarRanking();
    //Función que muestra la peor calificación de todas
    mostrarPeorCalificacion();
}
void emitirAlertas() {
    printf("\n[!] Funcion para EMITIR ALERTAS en construccion...\n");
    // Aquí irá la lógica para revisar promedios < 70 y últimas notas.
}
void generarHistograma() {
    printf("\n[!] Funcion para GENERAR HISTOGRAMA en construccion...\n");
    // Aquí irá la lógica para contar las notas en cada rango y mostrarlas.
    // Hola broski
}
void calcularPromediosEstudiante(){
    printf("\n[!] Funcion para CALCULAR PROMEDIOS POR ESTUDIANTE en construccion...\n");
}
void calcularPromediosEvaluacion(){
    printf("\n[!] Funcion para CALCULAR PROMEDIOS DEL GRUPO POR EVALUACION en construccion...\n");
}
void generarRanking(){
    printf("\n[!] Funcion para GENERAR RANKING en construccion...\n");
}
void mostrarPeorCalificacion(){
    printf("\n[!] Funcion para MOSTRAR LA PEOR CALIFICACION en construccion...\n");
}