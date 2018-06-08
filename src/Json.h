#ifndef JSON_H_
#define JSON_H_


typedef struct _Njson {
	char* clave;
	int* valor;
	//void (*funcion_imprimir)(void*);
} Njson;

typedef struct _Json {
	char* nombre;
	Njson** lista;
	int cantidad;
} Json;


void json_init(Json* this, Njson** lista, int cant);

void liberar_nombre(Json* this);

Json* njson_agregar_nodo(Json* this, Njson* nodo);

Njson* njson_agregar_dato_al_nodo(Njson* this, char* nombre, int* valor, unsigned tam_valor);

void njson_imprimir(Json* this);

void njson_generar_en_archivo(Json* this, char destino);





//Metodos Valor
//void valor_init(Valor* thisvalor);

#endif /* JSON_H_ */
