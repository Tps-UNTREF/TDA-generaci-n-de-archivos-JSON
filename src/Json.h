
#ifndef JSON_H_
#define JSON_H_


struct n_json{ // "size": "0 bytes" | "contents": ["size" :"2.3 MB", "rev.. ] ]
	char* clave;
	struct n_json *valor;
};


typedef struct _Json {
	struct n_json *clave_valor;
} Json;

void imprimir_json_consola(Json* this);
void generar_json_en_archivo(Json* this, char destino);


#endif /* JSON_H_ */
