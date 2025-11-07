//Uso de ifndef, define y endif para evitar la duplicación de la librería/header
#ifndef HISTOGRAMAS_H
#define HISTOGRAMAS_H

extern float promedioEstudiantes[40]; //Variable extern: Para su uso en cualquier archivo. Variable que se encuentra definida en otro lugar pero con acceso a ella. 

// void calcularPromedios(int Calificaciones[40][5], int Estudiantes, int Evaluaciones);

//Declaración de funciones necesarias para definirlas en histogramas.c.
void asignarPosicion(float promedio); // Asigna la cantidad de promedios dentro de un rango en la posición correspondiente.
void mostrarHistograma(int estudiantes); // Empieza a dibujar el histograma.
void iniciarHistograma(int Estudiantes); // La función principal que dará inicio al proceso de generación del histograma.
#endif