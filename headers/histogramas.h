#ifndef HISTOGRAMAS_H
#define HISTOGRAMAS_H

extern int calificaciones[40][5]; 
extern int numeroEstudiantes;
extern int numeroEvaluaciones;

void calcularPromedios(float Calificaciones[40][5], int Estudiantes, int Evaluaciones);
void asignarPosicion(float promedio);
void mostrarHistograma(int estudiantes);
void iniciarHistograma(float Calificaciones[40][5], int Estudiantes, int Evaluaciones);
#endif