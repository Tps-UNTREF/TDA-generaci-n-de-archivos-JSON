#ifndef JSON_H_
#define JSON_H_

typedef struct _Njson {
	char* clave;
	int elementos;
	int tipo;
	void* valor;
	void (*funcion_imprimir)(void*);
	void (*funcion_escribir)(FILE*,void*);
} Njson;

typedef struct _Json {
	Njson** lista;
	int cantidad;
} Json;


void json_init(Json* this, Njson** lista, int cant);

void json_liberar(Json* this);

void njson_liberar(Njson* nodo);

void njson_cambiar_valor(Json* this,char* clave_buscar, void* valor,int elementos, unsigned tipo,
							void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*));

Json* json_agregar_njson(Json* this, Njson* nodo);

Njson* njson_agregar_dato(Njson* this, char* nombre, void* valor,int elementos, unsigned tipo,
							void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*));

void json_imprimir(Json* this);

void njson_imprimir(Njson* this);

#endif /* JSON_H_ */
