#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Json.h"

void njson_init(Json* this) {
	this->nombre = malloc(strlen("njson"));
	strcpy(this->nombre, "njson");
	this->valor->dato = 0x0;
	this->valor->nombre = 0x0;
	this->valor->prox_elem = 0x0;
	this->valor->funcion_imprimir = 0x0;
}

void valor_init(Valor* thisvalor) {
	thisvalor->nombre = 0x0;
	thisvalor->dato = 0x0;
	thisvalor->prox_elem = 0x0;
	thisvalor->funcion_imprimir = 0x0;
}

void njson_agregar_dato(Json* this, char* nombre, void* valor, unsigned tam_valor, void (*funcion_imprimir)(void*)) {
	if(this->valor->dato == 0x0) {
		this->valor->nombre = malloc(strlen(nombre)+1);
		strcpy(this->valor->nombre, nombre);
		this->valor->dato = malloc(tam_valor);
		memcpy(this->valor->dato, valor, tam_valor);
		this->valor->funcion_imprimir = funcion_imprimir;
//		printf("%s: %s\n", this->valor->nombre, *(char*)(this->valor->dato));
	} else {

		//todo buscar el proximo elemento del valor que este vacio

		Valor proximo;
		valor_init(&proximo);
		this->valor->prox_elem = &proximo;
		this->valor->prox_elem->nombre = malloc(strlen(nombre)+1);
		strcpy(this->valor->prox_elem->nombre, nombre);
		this->valor->prox_elem->dato = malloc(tam_valor);
		memcpy(this->valor->prox_elem->dato, valor, tam_valor);
		printf("%s: %d\n", this->valor->prox_elem->nombre, *(int*)(this->valor->prox_elem->dato));
	}
}

void liberar_nombre(Json* this) {
	free(this->nombre);
	this->nombre = 0x0;
	free(this->valor->dato);
	free(this->valor->nombre);
	this->valor->dato = 0x0;
	this->valor->nombre = 0x0;

}

void njson_imprimir(Json* this) {
	printf("%s: ", this->valor->nombre);
//	this->valor->funcion_imprimir(this->valor->dato);
}

void njson_generar_en_archivo(Json* json, char destino) {

}
