#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Json.h"

/**
 * Precondición: Entra un Json existente, una lista existente y una cant mayor que 0
 * Postcondición: Inicia el Json
 * Parámetro this: Json a iniciar
 * Parámetro lista: Lista de nodos
 * Parámetro cant: Cantidad de nodos en la lista
 */
void json_init(Json* this, Njson** lista, int cant){

	this->cantidad = cant;

	this->lista = malloc(cant*sizeof(Njson));

	memcpy(this->lista,lista,cant*sizeof(Njson));

}

/**
 * Precondición: Ingresa un nodo existente
 * Postcondición: Imprime la clave y el valor del nodo
 * Parámetro nodo: Nodo a imprimir
 */
void njson_imprimir(Njson* nodo){

    if(nodo->elementos == 1){
        printf(" \"%s\" :", nodo->clave);
        (*(nodo->funcion_imprimir))(nodo->valor);
    }else{
        printf("\"%s\": [", nodo->clave);

        for(int i = 0; i < nodo->elementos; i++){

        	if(i != 0){
        		printf(",");
        	}

            (*(nodo->funcion_imprimir))(nodo->valor + (i*nodo->tipo));


        }
        printf("]");
    }

}

/**
 * Precondición: Ingresa un nodo existente
 * Postcondición: Libera el nodo
 * Parámetro nodo: Nodo a liberar
 */
void njson_liberar(Njson* nodo){

	if(nodo!=0x0){

		free(nodo->clave);
		free(nodo->valor);
		nodo->clave = 0x0;
		nodo->valor = 0x0;
	}

}

/**
 * Precondición: Ingresa un njson existente, un nombre valido, un valor valido, la cantidad de elementos, el tamaño del tipo de dato y la función de impresión
 * Postcondición: Agrega los datos a un njson
 * Parámetro this: Njson donde se agregará los datos
 * Parámetro nombre: Clave del nodo
 * Parámetro valor: Valor del nodo
 * Parámetro elementos: Cantidad de elementos
 * Parámetro tipo: tamaño del tipo del valor
 * Parámetro funcion_imprimir: Función de impresión
 */
Njson* njson_agregar_dato(Njson* this, char* nombre, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*)){

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

/**
 * Precondición: Ingresa un Json existente y un nodo existente y no vacio
 * Postcondición: Agrega nodo al Json
 * Parámetro this: Json donde se agregará el nodo
 * Parámetro nodo: Nodo a agregar
 */
Json* json_agregar_njson(Json* this, Njson* nodo){

	if(nodo != 0x0){

		this->cantidad++;

		this->lista = (Njson**)realloc(this->lista,this->cantidad*sizeof(Njson));

    	this->lista[this->cantidad-1] = nodo;


    }

	return this;

}

//pre: las claves son unicas, no debe haber repetidas.
/**
 * Precondición: Ingresa un Json existente, una clave existente en el Json, un nuevo valor, la cantidad de elementos, el tamaño del tipo del valor y la función de impresión
 * Postcondición: Modifica el valor de un nodo
 * Parámetro this: Json que contiene el nodo a modificar
 * Parámetro clave_buscar: Clave del nodo a modificar
 * Parámetro valor: Nuevo valor del nodo
 * Parámetro elementos: Cantidad de elementos
 * Parámetro tipo: Tamaño del tipo del valor
 * Parámetro funcion_escribir: Función de impresión
 */
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

/**
 * Precondición: Ingresa un Json existente
 * Postcondición: Libera el Json y cada uno de sus nodos
 * Parámetro this: Json a liberar
 */
void json_liberar(Json* this) {
	if(this->lista){

		for(int i = 0; i < this->cantidad; i++){

			njson_liberar(this->lista[i]);
		}

		free(this->lista);

	}

	this->lista = 0x0;
}

/**
 * Precondición: Ingresa un Json existente
 * Postcondición: Imprime el Json
 * Parámetro this: Json a imprimir
 */
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

/**
 * Precondición: Ingresa un archivo y un Json existente
 * Postcondición: Escribe el Json en el archivo
 * Parámetro archivo_de_salida: Archivo donde se escribirá el Json
 * Parámetro this: Json que se escribirá
 */
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

/**
 * Precondición: Ingresa un archivo y un njson existente
 * Postcondición: Escribe el njson en el archivo
 * Parámetro archivo_de_salida: Archivo donde se escribirá el njson
 * Parámetro this: njson que se escribirá
 */
void njson_escribir_en_archivo(FILE* archivo_de_salida,Njson* nodo){

    if(nodo->elementos == 1){
        fprintf(archivo_de_salida," \"%s\" :", nodo->clave);
        (*(nodo->funcion_escribir))(archivo_de_salida,nodo->valor);
    }else{
    	fprintf(archivo_de_salida,"\"%s\": [", nodo->clave);

        for(int i = 0; i < nodo->elementos; i++){

        	if(i != 0){
        		fprintf(archivo_de_salida,",");
        	}

            (*(nodo->funcion_escribir))(archivo_de_salida,nodo->valor + (i*nodo->tipo));

        }
        fprintf(archivo_de_salida,"]");
    }

}
