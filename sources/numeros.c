#include <stdio.h>

int getInt(){
    int digito = 0, n = 0;
    do
    {
        n = scanf("%d", &digito);
        if (n !=1)
        {
            printf("Por favor, ingresa un número: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                // Descarta caracteres
            }
        }
    } while (n!=1);
    return digito;
}

float getFloat(){
    float digito = 0.0f;
    int n = 0;
    do
    {
        n = scanf("%f", &digito);
        if (n !=1)
        {
            printf("Por favor, ingresa un número: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                // Descarta caracteres
            }
        }
    } while (n!=1);
    return digito;
}