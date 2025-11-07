#ifndef REPORTES_H //if not defined (si no está definido) reportes.h
#define REPORTES_H //entonces lo definimos, para evitar que se duplique

extern int calificaciones[40][5];
extern char nombresEstudiantes[40][25];
extern float promediosEstudiantes[40];

void mostrarReportes();
void calcularPromedioEvaluacion();
void calcularPromedioEstudiante();
void generarRanking();

#endif