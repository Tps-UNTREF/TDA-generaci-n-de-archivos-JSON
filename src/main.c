#include <stdio.h>
#include "json.h"
#include <stdbool.h>

void imprimir_int(void* dato) {
	printf("%d\n", *(int*)(dato));
}

void imprimir_double(void* dato) {
	printf("%f\n", *(double*)dato);
}

void imprimir_char(void* dato) {
	printf("%c\n", *(char*)dato);
}

void imprimir_float(void* dato) {
	printf("%f\n", *(double*)dato);
}

void imprimir_boolean(void* dato) {

	if(*(bool*)dato){

		printf("%s"," -true");

	}else{

		printf("%s"," -falso");

	}
}

int main() {

	Njson nodo;
//	Njson nodo2;
//	Njson nodo3;
//	Njson nodo4;
	Json n_json;
	Njson* lista[1];
//	int uno = 1;
//	char* dos = "hola";
//	int tres[3] = {1,2,3};
//	int cuatro = 4;
//	double coma = 2.0;
	bool mas = false;
	int modo;
	printf(
			"Por favor elija un modo: \n1-Crear Json\n2-Imprimir Json Consola\n3-Guardar Json en un archivo\n ");
	fflush( stdout);
	scanf("%d", &modo);
	switch (modo) {
	case (1):
	    lista[0] = (njson_agregar_dato_al_nodo(&nodo,"bool",&mas,1,sizeof(bool),&imprimir_boolean));
	    json_init(&n_json, lista,1);
//	    njson_agregar_dato_al_nodo(&nodo2,"dos",dos,4,sizeof(char),&imprimir_char);
//	    json_agregar_nodo(&n_json,&nodo2);
//	    njson_agregar_dato_al_nodo(&nodo3,"tres",&tres,3,sizeof(int),&imprimir_int);
//	    njson_agregar_dato_al_nodo(&nodo4,"double",&coma,1,sizeof(double),&imprimir_double);
//	    json_agregar_nodo(&n_json,&nodo3);
//	    json_agregar_nodo(&n_json,&nodo4);
//	    njson_cambiar_valor(&n_json,"uno",&cuatro,sizeof(int),&imprimir_int);
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
