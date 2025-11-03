#include <stdio.h>
#include <string.h>
#include "../headers/reportes.h"

void mostrarReportes(){

}
void calcularPromedioEstudiante(){
    float promedio;
    printf("\n--- PROMEDIOS GENERALES DE LOS ESTUDIANTES DURANTE SUS %d EVALUACIONES ---", numeroEvaluaciones);
    for(int i=0;i<numeroEstudiantes;i++){//El ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
        promedio=0.0;
        for(int j=0;j<numeroEvaluaciones;j++){//El ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
            promedio+=calificaciones[i][j];//Sumamos las calificaciones de cada alumno en todas sus evaluaciones
        }
        promedio/=numeroEvaluaciones;//Se divide la suma de sus calificaciones en todas sus evaluaciones entre el numero de evaluaciones
        promediosEstudiantes[i]=promedio;
        printf("\nEstudiante %d: %d", (i+1),promedio);
    }
}
void calcularPromedioEvaluacion(){
    float promedio;
    printf("\n--- PROMEDIO GENERALES DEL GRUPO EN LAS EVALUACIONES ---");
    for(int j=0;j<numeroEvaluaciones;j++){//El ciclo solo recorre hasta el limite necesario (el numero de evaluaciones)
        promedio = 0.0;
        for(int i=0;i<numeroEstudiantes;i++){//El ciclo solo recorre hasta el limite necesario (el numero de estudiantes)
            promedio+=calificaciones[i][j];//Sumamos todas las calificaciones del grupo en la evaluacion en curso del ciclo
        }
        promedio/=numeroEstudiantes;//Se divide la suma de todas las calificaciones del grupo en esa evaluacion entre el tamaño del grupo(el numero de estudiantes)
        printf("\n- Promedio general del grupo en la evaluación %d: %d",(j+1),promedio);
    }
}
void generarRanking(){
    // 1. Definimos el struct.
    // Esta struct solo existe dentro de esta función.
    struct EstudianteRanking{
        char nombre[50];
        float promedio;
    };
    // 2. Creamos un arreglo con estas "características"
    // una por cada estudiante.
    struct EstudianteRanking ranking[numeroEstudiantes];
    // 3. Llenamos el arreglo de ranking
    for (int i=0;i<numeroEstudiantes; i++) {
        // Guardamos los datos JUNTOS en esa "caja"
        ranking[i].promedio=promediosEstudiantes[i];
        strcpy(ranking[i].nombre,nombresEstudiantes[i]);
        //Se copia el 2do parámetro en el 1er parámetro
    }
    // 4. Ordenamos el arreglo de con el método de ordenamiento por selección
    // Comparamos los promedios e intercambiamos el arreglo entero
    for(int i=0;i<numeroEstudiantes;i++){
        //Suponemos que el maximo es el primer elemento
        int maximo=i;
        //Empezamos a recorrer el resto del arreglo a partir del elemento siguiente a i (i+1)
        for(int j=i+1;j<numeroEstudiantes;j++){
            //Si el promedio en J es mayor al promedio que suponemos es maximo, entonces ahora maximo es J
            if(ranking[j].promedio>ranking[maximo].promedio){
                maximo=j;
            }
        }
        //** RECORDAR EL VALOR A INTERCAMBIAR
        //Usamos una variable auxiliar para  no perder los datos en i
        struct EstudianteRanking aux=ranking[i];
        //** INTERCAMBIAR LOS VALORES
        //Ahora los datos en i son los que hay en maximo, ya que al volver a iniciar el ciclo, i sera el maximo
        ranking[i]=ranking[maximo];
        //Aquu concretamos el intercambio asignando los datos de la variable aux
        ranking[maximo]=aux;
    }
    // 5. Mostramos el Top 3
    printf("\n--- RANKING (TOP 3) ---\n");
    // Nos aseguramos de no intentar mostrar 3 si hay menos de 3 estudiantes, mediante el operador ternario ?
    int topN=(numeroEstudiantes < 3)?numeroEstudiantes:3;
    //Si el numero de estudiantes es menor a 3 topN=numeroEstudiantes, si no, topN=3
    for (int i = 0; i < topN; i++){
        printf("%d. %s - Promedio: %.2f\n", i + 1,ranking[i].nombre,ranking[i].promedio);
    }
    //6. Mostramos la peor calificación del grupo
    if (numeroEstudiantes>0) {
        printf("\n--- PEOR PROMEDIO DEL GRUPO ---\n");
        printf("%s - Promedio: %.2f\n", ranking[numeroEstudiantes - 1].nombre,ranking[numeroEstudiantes-1].promedio);
    }
}