#include <stdio.h>
#include "json.h"

void imprimir_int(void* dato) {
	printf("%d\n", *(int*)dato);
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

}

void imprimir_array(void* dato) {

}

int main() {

	Njson nodo;
	Njson nodo2;
	Json n_json;
	Njson* lista;
	int uno = 1;
	int dos = 2;
	int modo;
	printf(
			"Por favor elija un modo: \n1-Crear Json\n2-Imprimir Json Consola\n3-Guardar Json en un archivo\n ");
	fflush( stdout);
	scanf("%d", &modo);
	switch (modo) {
	case (1):
	    lista = (njson_agregar_dato_al_nodo(&nodo,"uno",&uno,sizeof(int)));
	    json_init(&n_json, &lista,1);
	    njson_agregar_nodo(&n_json,njson_agregar_dato_al_nodo(&nodo2,"dos",&dos,sizeof(int)));
		njson_imprimir(&n_json);
		liberar_nombre(&n_json);
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
