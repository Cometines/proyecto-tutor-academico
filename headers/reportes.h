#ifndef REPORTES_H //if not defined (si no está definido) reportes.h
#define REPORTES_H //entonces lo definimos, para evitar que se duplique

extern int calificaciones[40][5];
extern char nombresEstudiantes[40][25];
extern int numeroEstudiantes=0;
extern int numeroEvaluaciones=0;

void mostrarReportes();
void calcularPromedioEvaluacion();
void calcularPromedioEstudiante();
void calcularRanking();
void mostrarPeorCalificacion();

#endif