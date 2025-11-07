#include <stdio.h>
#include <stdlib.h> // Para system()

// --- Detección del Sistema Operativo ---

#ifdef _WIN32
    // Si es Windows, incluir la librería de Windows para Sleep()
    #include <windows.h>
#else
    // Si no es Windows (asumimos UNIX: Linux/macOS), incluir unistd.h
    #include <unistd.h> // Para usleep()
#endif

// ----------------------------------------

void limpiarConsola() {
    #ifdef _WIN32
        // Código para Windows
        system("cls");
    #else
        // Código para UNIX (Linux/macOS)
        system("clear");
    #endif
}

void pausarMilisegundos(int milisegundos) {
    #ifdef _WIN32
        // Windows usa Sleep() con milisegundos
        Sleep(milisegundos);
    #else
        // UNIX usa usleep() con microsegundos (1ms = 1000 microsegundos)
        usleep(milisegundos * 1000);
    #endif
}