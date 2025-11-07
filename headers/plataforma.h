#ifndef PLATAFORMA_H
#define PLATAFORMA_H

/**
 * Esta función limpia la pantalla de la consola (compatible con Windows y UNIX).
 */
void limpiarConsola();

/**
 * Esta funcion pausa la ejecución del programa por un número de milisegundos.
 * Recibe el tiempo a esperar en milisegundos como parámetro.
 */
void pausarMilisegundos(int milisegundos);

#endif