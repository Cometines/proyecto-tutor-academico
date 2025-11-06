#ifndef CAPTURA_H //if not defined (si no esta definido)
#define CAPTURA_H //se define la libreria para que no se duplique 

extern int calificaciones[40][5];
extern char nombresEstudiantes[40][25];

int capturarEstudiantescant();

int capturarEvaluacionescant();

void capturarCalificaciones(int numeroEstudiantes, int numeroEvaluaciones);

#endif
