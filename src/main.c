#include <stdio.h>
#include "json.h"

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
		njson_agregar_dato(&n_json, "Dato 1", &uno, sizeof(int));
		njson_agregar_dato(&n_json, "Dato 2", &cinco, sizeof(int));
//		njson_agregar_dato(&n_json, "Dato 3", &siete, sizeof(int));
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
