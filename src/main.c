#include <stdio.h>
#include "json.h"

int main(int argc, char** argv) {
	int modo;

	Json *json;

	printf(
			"Por favor elija un modo: \n1-Imprimir Json Consola\n2-Guardar Json en un archivo\n ");
	fflush( stdout);
	scanf("%d", &modo);
	switch (modo) {
	case (1):
		break;
	case (2):
		break;
	default:
		printf("Por favor elija 1 o 2");
		break;
	}
	return 0;
}
