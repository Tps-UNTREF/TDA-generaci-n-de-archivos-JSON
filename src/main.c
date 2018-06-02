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

int main(int argc, char** argv) {
	Json n_json;
	int modo;
	printf(
			"Por favor elija un modo: \n1-Crear Json\n2-Imprimir Json Consola\n3-Guardar Json en un archivo\n ");
	fflush( stdout);
	scanf("%d", &modo);
	switch (modo) {
	case (1):
		njson_init(&n_json);
		int uno = 1;
		int cinco = 5;
		int siete = 7;
		njson_agregar_dato(&n_json, "Dato 1", &uno, sizeof(int), &imprimir_int);
//		njson_agregar_dato(&n_json, "Dato 2", &cinco, sizeof(int));
//		njson_agregar_dato(&n_json, "Dato 3", &siete, sizeof(int));
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
