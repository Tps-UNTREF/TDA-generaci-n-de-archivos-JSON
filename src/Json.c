#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Json.h"

void json_init(Json* this, Njson** lista, int cant){

	this->nombre = malloc(strlen("njson"));

	strcpy(this->nombre,"njson");

	this->cantidad = cant;

	this->lista = malloc(cant*sizeof(Njson));

	memcpy(this->lista,lista,cant*(sizeof(Njson)));

}


Njson* njson_agregar_dato_al_nodo(Njson* this, char* nombre, int* valor, unsigned tam_valor){

	this->clave = (char*)malloc(strlen(nombre) + 1);
	strcpy(this->clave, nombre);
	this->valor = malloc(tam_valor);
	memcpy(this->valor, valor, tam_valor);

	return this;
}

Json* njson_agregar_nodo(Json* this, Njson* nodo){

	if(nodo !=0x0){

    	this->lista = realloc(this->lista,2*sizeof(Njson));

    	memcpy(this->lista + 1*sizeof(Njson) ,nodo,sizeof(Njson));



    }

	return this;

}


void liberar_nombre(Json* this) {
	if(this->lista){
		free(this->nombre);
		this->nombre = 0x0;
		free (this->lista[0]->clave);
		this->lista[0]->clave = 0x0;
		free (this->lista[0]->valor);
		this->lista[0]->valor = 0x0;
		free (this->lista[1]->clave);
		this->lista[1]->clave = 0x0;
		free (this->lista[1]->valor);
		this->lista[1]->valor = 0x0;

	}

	free(this->lista);
	this->lista = 0x0;
}

void njson_imprimir(Json* this) {
	printf("%s: ", this->nombre);
	printf("%s: ", this->lista[0]->clave);
	printf("%d: ", *(int*)(this->lista[0]->valor));
	printf("%s: ", this->lista[1]->clave);
    printf("%d: ", *(int*)(this->lista[1]->valor));
}
