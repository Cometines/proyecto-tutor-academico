#ifndef ALERTAS_H //INICIO DEL BLOQUE , Si no esta definido el reporte
#define ALERTAS_H //evita que se duplique o se modifique
//extern dice que las variables si existen pero en otra parte del proyecto
extern int calificaciones[40][5];
extern char nombresEstudiantes[40][25];
extern int numeroEstudiantes=0;
extern int numeroEvaluaciones=0;

void emitirAlertas();
#endif //FIN DEL BLOQUE