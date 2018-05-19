#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Json.h"

void njson_init(Json* this) {
	this->nombre = malloc(strlen("njson"));
	strcpy(this->nombre, "njson");
	this->valor->dato = 0x0;
	this->valor->nombre = 0x0;
}

void valor_init(Valor* thisvalor) {
	thisvalor->nombre = 0x0;
	thisvalor->dato = 0x0;
}

void njson_agregar_dato(Json* this, char* nombre, int* valor, unsigned tam_valor) {
	if(this->valor->dato == 0x0) {
		Valor* w;
		this->valor->nombre = malloc(strlen(nombre)+1);
		strcpy(this->valor->nombre, nombre);
		this->valor->dato = malloc(tam_valor);
		memcpy(this->valor->dato, valor, tam_valor);
		valor_init(w);
		this->valor->prox_elem = w;
		printf("%s: %d\n", this->valor->nombre, *(this->valor->dato));
	} else {
		Valor* v = this->valor->prox_elem;
		while(v->dato != 0x0) {
			v = v->prox_elem;
		}
//		v->nombre = malloc(strlen(nombre)+1);
//		strcpy(v->nombre, nombre);
//		v->dato = malloc(tam_valor);
//		memcpy(v->dato, valor, tam_valor);
////		valor_init(v->prox_elem);
//		printf("%s: %d\n", v->prox_elem->nombre, *(v->prox_elem->dato));
	}
}

void liberar_nombre(Json* this) {
	free(this->nombre);
	this->nombre = 0x0;
	free(this->valor->dato);
	free(this->valor->nombre);
//	free(this->valor->prox_elem->nombre);
//	free(this->valor->prox_elem->dato);
//	free(this->valor->prox_elem->prox_elem->nombre);
//	free(this->valor->prox_elem->prox_elem->dato);
	this->valor->dato = 0x0;
	this->valor->nombre = 0x0;
//	this->valor->prox_elem->nombre = 0x0;
//	this->valor->prox_elem->dato = 0x0;
//	this->valor->prox_elem->prox_elem->nombre = 0x0;
//	this->valor->prox_elem->prox_elem->dato = 0x0;
}

void imprimir_json_consola(Json* this) {

}

void generar_json_en_archivo(Json* json, char destino) {

}
