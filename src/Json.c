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
        printf(" \"%s\" :", nodo->clave);
        (*(nodo->funcion_imprimir))(nodo->valor);
    }else{
        printf("%s: {", nodo->clave);

        for(int i = 0; i < nodo->elementos; i++){

            (*(nodo->funcion_imprimir))(nodo->valor + (i*nodo->tipo));
            printf(" ");

        }
        printf("}");
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


Njson* njson_agregar_dato_al_nodo(Njson* this, char* nombre, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*)){

	this->clave = (char*)malloc(strlen(nombre) + 1);
	strcpy(this->clave, nombre);
	this->valor = malloc(tipo*elementos);
	memcpy(this->valor, valor, tipo*elementos);
	this->funcion_imprimir = funcion_imprimir;
	this->funcion_escribir = funcion_escribir;
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

void njson_cambiar_valor(Json* this, char* clave_buscar, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*), void (*funcion_escribir)(FILE* archivo_de_salida,void*)){

		for(int i = 0; i < this->cantidad; i++){
			if(strcmp(this->lista[i]->clave,clave_buscar) == 0){

				this->lista[i]->valor = realloc(this->lista[i]->valor,tipo*elementos);
				memcpy(this->lista[i]->valor, valor, tipo*elementos);
			    this->lista[i]->funcion_imprimir = funcion_imprimir;
			    this->lista[i]->funcion_escribir = funcion_escribir;


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

	printf("{\n");

	for(int i = 0; i < this->cantidad; i++){

		  njson_imprimir(this->lista[i]);

		  if(i != (this->cantidad - 1)){
			 printf(",");
			 printf("\n");
		  }

	}
	printf("\n");
	printf("}");
}

void json_escribir_en_archivo(FILE* archivo_de_salida, Json* this){
	fprintf(archivo_de_salida,"{\n");

	for(int i = 0; i < this->cantidad; i++){

		  njson_escribir_en_archivo(archivo_de_salida,this->lista[i]);

		  if(i != (this->cantidad - 1)){
			 fprintf(archivo_de_salida,",");
			 fprintf(archivo_de_salida,"\n");
		  }

	}
	fprintf(archivo_de_salida,"\n");
	fprintf(archivo_de_salida,"}");
}

void njson_escribir_en_archivo(FILE* archivo_de_salida,Njson* nodo){

    if(nodo->elementos == 1){
        fprintf(archivo_de_salida," \"%s\" :", nodo->clave);
        (*(nodo->funcion_escribir))(archivo_de_salida,nodo->valor);
    }else{
    	fprintf(archivo_de_salida,"%s: {", nodo->clave);

        for(int i = 0; i < nodo->elementos; i++){

            (*(nodo->funcion_escribir))(archivo_de_salida,nodo->valor + (i*nodo->tipo));
            fprintf(archivo_de_salida," ");

        }
        fprintf(archivo_de_salida,"}");
    }

}
