#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float media_aritmetica(float datos[], int n) {
    float media = 0;
    int i;
    for(i = 0; i < n; i ++) {
        media += datos[i]/n;
    }
    return media;
}

float media_armonica(float datos[], int n) {
    float media_inv = 0;
    int i;
    for(i = 0; i < n; i ++) {
        media_inv += 1/datos[i];
    }
    return n/media_inv;
}

float media_geometrica(float datos[], int n) {
    float datos_log[n];
    int i;
    for(i = 0; i < n; i++) {
        datos_log[i] = log(datos[i]);
    }
    return exp(media_aritmetica(datos_log, n));
}

int main(int argc, char *argv[]) {

    if(argc < 3) printf("no hay suficientes argumentos\n");

    float datos[argc - 2]; int i;

    for(i = 2; i < argc; i++) 
        datos[i-2] = atof(argv[i]);
        
    char opcion = (strlen(argv[1]) == 1) ? argv[1][0] : 0;
    switch (opcion) {
        case 'A':
            printf("%.5f\n", media_aritmetica(datos, argc - 2)); 
            break;
    
        case 'H': 
            printf("%.5f\n", media_armonica(datos, argc - 2)); 
            break;
        case 'G': 
            printf("%.5f\n", media_geometrica(datos, argc - 2)); 
            break;
        default:
            printf("tipo de media no valida\n");
    }
    return 0;
}