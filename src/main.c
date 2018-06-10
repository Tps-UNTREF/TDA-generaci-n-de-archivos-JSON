#include <stdio.h>
#include "json.h"
#include <stdbool.h>

void imprimir_int(void* dato) {
    printf("%d", *(int*)(dato));
}

void imprimir_double(void* dato) {
    printf("%f", *(double*)dato);
}

void imprimir_char(void* dato) {
    printf("%c", *(char*)dato);
}

void imprimir_float(void* dato) {
    printf("%f", *(double*)dato);
}

void imprimir_boolean(void* dato) {

    if(*(bool*)dato){

        printf("%s","true");

    }else{

        printf("%s","falso");

    }
}

int main() {

    Njson nodo;
    Njson nodo2;
    Njson nodo3;
    Njson nodo4;
    Njson nodo5;
    Json n_json;
    Njson* lista[1];
    int uno = 1;
    char* saludo = "hola";
    int array[3] = {1,2,3};
    int cuatro = 4;
    double coma = 2.0;
    bool booleano = false;
    int modo;
    printf(
            "Por favor elija un modo: \n1-Crear Json\n2-Imprimir Json Consola\n3-Guardar Json en un archivo\n ");
    fflush( stdout);
    scanf("%d", &modo);
    switch (modo) {
    case (1):
        lista[0] = (njson_agregar_dato_al_nodo(&nodo,"Booleano",&booleano,1,sizeof(bool),&imprimir_boolean));
        json_init(&n_json, lista,1);
        njson_agregar_dato_al_nodo(&nodo2,"Saludo",saludo,4,sizeof(char),&imprimir_char);
        json_agregar_nodo(&n_json,&nodo2);
        njson_agregar_dato_al_nodo(&nodo3,"Array",&array,3,sizeof(int),&imprimir_int);
        njson_agregar_dato_al_nodo(&nodo4,"Coma",&coma,1,sizeof(double),&imprimir_double);
        json_agregar_nodo(&n_json,&nodo3);
        json_agregar_nodo(&n_json,&nodo4);
        njson_agregar_dato_al_nodo(&nodo5,"Uno",&uno,1,sizeof(int),&imprimir_int);
        json_agregar_nodo(&n_json,&nodo5);
        njson_cambiar_valor(&n_json,"Uno",&cuatro,1,sizeof(int),&imprimir_int);
        json_imprimir(&n_json);
        liberar_json(&n_json);
        break;
    case (2):
        break;
    case (3):
        break;
    default:
        printf("Por favor elija 1 o 2");
        break;
    }
    return 0;
}
