#include <stdio.h>
#include "json.h"
#include <stdbool.h>

void imprimir_int(void* dato) {
    printf("%d", *(int*)(dato));
}

void imprimir_double(void* dato) {
    printf("%f", *(double*)dato);
}

void imprimir_string(void* dato){

	printf("%s",(char*)dato);

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

void imprimir_json(void* this) {

	printf("{\n");

	for(int i = 0; i < ((Json*)(this))->cantidad; i++){

		njson_imprimir(((Json*)(this))->lista[i]);
	}
	printf("}");
}

int main() {

    Njson nodo1;
    Njson nodo2;
    Njson nodo3;
    Njson nodo4;
//    Njson nodo5;
//    Njson nodo6;
//    Njson nodo7;
//    Njson nodo8;
//    Njson nodo9;
//    Njson nodo10;
    Json principal;
//    Json secundario;
//    Json terciario;
//    bool is_dir = false;
    bool thumb_exists = true;
    int bytes = 0;
    int modo;
    printf(
            "Por favor elija un modo: \n1-Crear Json\n2-Imprimir Json Consola\n3-Guardar Json en un archivo\n ");
    fflush( stdout);
    scanf("%d", &modo);
    switch (modo) {
    case (1):

		  njson_agregar_dato_al_nodo(&nodo1,"Size","0 bytes",1,sizeof(char*),&imprimir_string);
          njson_agregar_dato_al_nodo(&nodo2,"Hash","3764154sdas64564da54",1,sizeof(char*),&imprimir_string);
          njson_agregar_dato_al_nodo(&nodo3,"Bytes",&bytes,1,sizeof(int),&imprimir_int);
          njson_agregar_dato_al_nodo(&nodo4,"Thumb_exists",&thumb_exists,1,sizeof(bool),&imprimir_boolean);
          Njson* lista[4] = {&nodo1,&nodo2,&nodo3,&nodo4};
          json_init(&principal,lista,4);
          json_imprimir(&principal);
          liberar_json(&principal);

//        lista[0] = (njson_agregar_dato_al_nodo(&nodo,"Booleano",&booleano,1,sizeof(bool),&imprimir_boolean));
//        json_init(&n_json, lista,1);
//        njson_agregar_dato_al_nodo(&nodo2,"Saludo",saludo,1,sizeof(char*),&imprimir_string); //string es un elemento...
//        json_agregar_nodo(&n_json,&nodo2);
//        njson_agregar_dato_al_nodo(&nodo3,"Array",&array,3,sizeof(int),&imprimir_int);
//        njson_agregar_dato_al_nodo(&nodo4,"Coma",&coma,1,sizeof(double),&imprimir_double);
//        json_agregar_nodo(&n_json,&nodo3);
//        json_agregar_nodo(&n_json,&nodo4);
//        njson_agregar_dato_al_nodo(&nodo5,"Uno",&uno,1,sizeof(int),&imprimir_int);
//        json_agregar_nodo(&n_json,&nodo5);
//        njson_cambiar_valor(&n_json,"Uno",&cuatro,1,sizeof(int),&imprimir_int);
//        json_imprimir(&n_json);
//        liberar_json(&n_json);
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
