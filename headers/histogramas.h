#ifndef HISTOGRAMAS_H
#define HISTOGRAMAS_H

extern int calificaciones[40][5]; 
extern int numeroEstudiantes;
extern int numeroEvaluaciones;

void calcularPromedios(int Calificaciones[40][5], int Estudiantes, int Evaluaciones);
void asignarPosicion(int promedio);
void mostrarHistograma(int estudiantes);
void iniciarHistograma(int Calificaciones[40][5], int Estudiantes, int Evaluaciones);
#endif