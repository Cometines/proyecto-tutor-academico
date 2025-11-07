#ifndef CAPTURA_H //if not defined (si no esta definido)
#define CAPTURA_H //se define la libreria para que no se duplique 

extern float calificaciones[40][5];
extern char nombresEstudiantes[40][50];
extern float promediosEstudiantes[40];

int capturarNumeroEstudiantes();

int capturarNumeroEvaluaciones();

void capturarCalificaciones(int numeroEstudiantes, int numeroEvaluaciones);

void calcularPromedioEstudiante(int num_estudiantes, int num_evaluaciones);

#endif
