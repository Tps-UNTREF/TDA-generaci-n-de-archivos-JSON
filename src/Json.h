#ifndef JSON_H_
#define JSON_H_

typedef struct _valor {
	char* nombre;
	int* dato;
	struct _valor* prox_elem;
//	void (*funcion_imprimir)(void*);
} Valor;

typedef struct _Json {
	char* nombre;
	Valor* valor;
} Json;

void njson_init(Json* this);

void liberar_nombre(Json* this);

void njson_agregar_dato(Json* this, char* nombre, int* valor, unsigned tam_valor);

void imprimir_json_consola(Json* this);
void generar_json_en_archivo(Json* this, char destino);





//Metodos Valor
void valor_init(Valor* thisvalor);

#endif /* JSON_H_ */
