#include <stdio.h>

int main() {
	int modo;
	printf(
			"Por favor elija un modo: \n1-Imprimir Json Consola\n2-Guardar Json en un archivo\n ");
	fflush( stdout);
	scanf("%d", &modo);
	switch (modo) {
	case (1):
		//Imprimir Json
		break;
	case (2):
		//Guardar Json en archivo
		break;
	default:
		printf("Por favor elija 1 o 2");
		break;
	}
	return 0;
}
