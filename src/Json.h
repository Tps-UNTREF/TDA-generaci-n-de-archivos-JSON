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

void liberar_json(Json* this);

void liberar_nodo(Njson* nodo);

void njson_cambiar_valor(Json* this,char* clave_buscar, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*));

Json* json_agregar_nodo(Json* this, Njson* nodo);

Njson* njson_agregar_dato_al_nodo(Njson* this, char* nombre, void* valor,int elementos, unsigned tipo, void (*funcion_imprimir)(void*),void (*funcion_escribir)(FILE* archivo_de_salida,void*));

void json_imprimir(Json* this);

void njson_imprimir(Njson* this);

void njson_generar_en_archivo(Json* this, char destino);

//Metodos Valor
//void valor_init(Valor* thisvalor);

#endif /* JSON_H_ */
