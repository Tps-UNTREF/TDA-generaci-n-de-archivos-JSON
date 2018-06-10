#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Json.h"

void json_init(Json* this, Njson** lista, int cant){

	this->cantidad = cant;

	this->lista = malloc(cant*sizeof(Njson));

	memcpy(this->lista,lista,cant*sizeof(Njson));

}


void njson_imprimir(Njson* nodo){

    if(nodo->elementos == 1){
        printf("%s: ", nodo->clave);
        (*(nodo->funcion_imprimir))(nodo->valor);
        printf("\n");
    }else{

        printf("%s: [", nodo->clave);

        for(int i = 0; i < nodo->elementos; i++){

            (*(nodo->funcion_imprimir))(nodo->valor + (i*nodo->tipo));
            printf(" ");

        }
        printf("]\n");
    }

}

void liberar_nodo(Njson* nodo){

	if(nodo!=0x0){

		free(nodo->clave);
		free(nodo->valor);
		nodo->clave = 0x0;
		nodo->valor = 0x0;
	}

}


Njson* njson_agregar_dato_al_nodo(Njson* this, char* nombre, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*)){

	this->clave = (char*)malloc(strlen(nombre) + 1);
	strcpy(this->clave, nombre);
	this->valor = malloc(tipo*elementos);
	memcpy(this->valor, valor, tipo*elementos);
	this->funcion_imprimir = funcion_imprimir;
	this->elementos = elementos;
	this->tipo = tipo;

	return this;
}

Json* json_agregar_nodo(Json* this, Njson* nodo){

	if(nodo != 0x0){

		this->cantidad++;

		this->lista = (Njson**)realloc(this->lista,this->cantidad*sizeof(Njson));

    	this->lista[this->cantidad-1] = nodo;


    }

	return this;

}

//pre: las claves son unicas, no debe haber repetidas.

void njson_cambiar_valor(Json* this, char* clave_buscar, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*)){

		for(int i = 0; i < this->cantidad; i++){
			if(strcmp(this->lista[i]->clave,clave_buscar) == 0){

				this->lista[i]->valor = realloc(this->lista[i]->valor,tipo*elementos);
				memcpy(this->lista[i]->valor, valor, tipo*elementos);
			    this->lista[i]->funcion_imprimir = funcion_imprimir;

			}
    }
}

void liberar_json(Json* this) {
	if(this->lista){

		for(int i = 0; i < this->cantidad; i++){

			liberar_nodo(this->lista[i]);
		}

		free(this->lista);

	}

	this->lista = 0x0;
}

void json_imprimir(Json* this) {

	for(int i = 0; i < this->cantidad; i++){

		njson_imprimir(this->lista[i]);
	}
}
