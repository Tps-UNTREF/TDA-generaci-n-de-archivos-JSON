#include <stdio.h>
#include "json.h"
#include <stdbool.h>
#include <string.h>

/**
 * Funciones para imprimir de cada tipo
 * Precondición: Entra un dato de tipo void
 * Postcondición: Imprime el dato dependiendo de su tipo
 */
void imprimir_int(void* dato) {
	printf("%d", *(int*) (dato));
}

void imprimir_double(void* dato) {
	printf("%f", *(double*) dato);
}

void imprimir_string(void* dato) {

	printf(" \"%s\" ", (char*) dato);

}

void imprimir_float(void* dato) {
	printf("%f", *(double*) dato);
}

void imprimir_boolean(void* dato) {

	if (*(bool*) dato) {

		printf("%s", "true");

	} else {

		printf("%s", "falso");

	}
}

/**
 * Funciones para escribir en el archivo de cada tipo
 * Precondición: Entra un archivo y un dato de tipo void
 * Postcondición: Escribe el dato en el archivo
 */
void escribir_en_archivo_int(FILE* archivo_de_salida,void* dato) {
	fprintf(archivo_de_salida,"%d", *(int*) (dato));
}

void escribir_en_archivo_double(FILE* archivo_de_salida,void* dato) {
	fprintf(archivo_de_salida,"%f", *(double*) dato);
}

void escribir_en_archivo_string(FILE* archivo_de_salida,void* dato) {

	fprintf(archivo_de_salida," \"%s\" ", (char*) dato);

}

void escribir_en_archivo_float(FILE* archivo_de_salida,void* dato) {
	fprintf(archivo_de_salida,"%f", *(double*) dato);
}

void escribir_en_archivo_boolean(FILE* archivo_de_salida,void* dato) {

	if (*(bool*) dato) {

		fprintf(archivo_de_salida,"%s", "true");

	} else {

		fprintf(archivo_de_salida,"%s", "falso");

	}
}

void escribir_en_archivo_json(FILE* archivo_de_salida,void* this) {

	fprintf(archivo_de_salida,"{\n");

	for (int i = 0; i < ((Json*) (this))->cantidad; i++) {

		njson_escribir_en_archivo(archivo_de_salida,((Json*) (this))->lista[i]);

		if (i != ((Json*) (this))->cantidad - 1) {
			fprintf(archivo_de_salida,",");
			fprintf(archivo_de_salida,"\n");
		}

	}
	fprintf(archivo_de_salida,"\n");
	fprintf(archivo_de_salida,"}");
}


void imprimir_json(void* this) {

	printf("{\n");

	for (int i = 0; i < ((Json*) (this))->cantidad; i++) {

		njson_imprimir(((Json*) (this))->lista[i]);

		if (i != ((Json*) (this))->cantidad - 1) {
			printf(",");
			printf("\n");
		}

	}
	printf("\n");
	printf("}");
}

int main(int argc, char** argv) {

	/**
	 * Creación de nodos
	 */
	Njson nodo1;
	Njson nodo2;
	Njson nodo3;
	Njson nodo4;
	Njson nodo5;
	Njson nodo6;
	Njson nodo7;
	Njson nodo8;
	Njson nodo9;
	Njson nodo10;
	Njson nodo11;
	Njson nodo12;
	Njson nodo13;
	Njson nodo14;
	Njson nodo15;
	Njson nodo16;
	Njson nodo17;
	Njson nodo18;
	Njson nodo19;
	Njson nodo20;
	Njson nodo21;
	Njson nodo22;
	Njson nodo23;
	Njson nodo24;
	Njson nodo25;
	Njson nodo26;
	Njson nodo27;

	/**
	 * Creación de Jsons
	 */
	Json principal;
	Json secundario;
	Json terciario;

	/**
	 * Creación de los datos
	 */
	bool is_dir = false;
	bool is_dir2 = false;
	bool thumb_exists = true;
	bool thumb_exists2 = true;
	double array[1];
	array[0] = 37.77256666666666;
	array[1] = 122.4593454545;
	int bytes = 5;
	int nuevobytes = 0;
	int bytes2 = 2456963;
	int revision = 14511;
	int revision2 = 29007;

	/**
	 *
	 * Agrega los datos al nodo
	 */
	njson_agregar_dato(&nodo1, "Size", "0 bytes", 1, sizeof("0 bytes"), &imprimir_string,&escribir_en_archivo_string);
	njson_agregar_dato(&nodo2, "Hash", "3764154sdas64564da54", 1, sizeof("3764154sdas64564da54"), &imprimir_string,&escribir_en_archivo_string);
	njson_agregar_dato(&nodo3, "Bytes", &bytes, 1, sizeof(int), &imprimir_int,&escribir_en_archivo_int);
	njson_agregar_dato(&nodo4, "Thumb_exists", &thumb_exists, 1, sizeof(bool), &imprimir_boolean,&escribir_en_archivo_boolean);
	njson_agregar_dato(&nodo5, "Rev", "3387392739hdh", 1, sizeof("3387392739hdh"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo6, "modified", "Wed, 27 Apr 2014 22:18:51 +0000", 1,
								sizeof("Wed, 27 Apr 2014 22:18:51 +0000"), &imprimir_string,&escribir_en_archivo_string);
	njson_agregar_dato(&nodo7, "Path", "/Photos", 1, sizeof("/Photos"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo8, "is_dir", &is_dir, 1, sizeof(bool), &imprimir_boolean, &escribir_en_archivo_boolean);
	njson_agregar_dato(&nodo9, "icon", "folder", 1, sizeof("folder"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo10, "root", "dropbox", 1, sizeof("dropbox"), &imprimir_string, &escribir_en_archivo_string);

	/**
	 * Creación del Json principal
	 */
	Njson* lista[10] = { &nodo1, &nodo2, &nodo3, &nodo4, &nodo5, &nodo6, &nodo7, &nodo8, &nodo9, &nodo10 };
	json_init(&principal, lista, 10);

	/**
	 * Agrega datos a otros nodos
	 */
	njson_agregar_dato(&nodo12, "Size", "2.3 MB", 1, sizeof("2.3 MB"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo13, "Rev", "4654dsd4s54d5", 1, sizeof("4654dsd4s54d5"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo14, "Thumb_exists", &thumb_exists2, 1, sizeof(bool), &imprimir_boolean, &escribir_en_archivo_boolean);
	njson_agregar_dato(&nodo15, "Bytes", &bytes2, 1, sizeof(int), &imprimir_int, &escribir_en_archivo_int);
	njson_agregar_dato(&nodo16, "modified", "Mon, 07 Apr 2013 01:12:02 +0000", 1,
								sizeof("Mon, 07 Apr 2013 01:12:02 +0000"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo17, "client mtime", "Thu, 29 Aug 2013 01:12:02 +0000", 1,
								sizeof("Thu, 29 Aug 2013 01:12:02 +0000"), &imprimir_string, &escribir_en_archivo_string);
	njson_agregar_dato(&nodo18, "Path", "/Photos/flowers.jpg", 1, sizeof("/Photos/flowers.jpg"), &imprimir_string, &escribir_en_archivo_string);

	/**
	 * Creación del Json secundario, que será contenido en el Json principal
	 */
	Njson* lista2[7] = { &nodo12, &nodo13, &nodo14, &nodo15, &nodo16, &nodo17, &nodo18 };
	json_init(&secundario, lista2, 7);

	/**
	 * Agrega datos a otros nodos
	 */
	njson_agregar_dato(&nodo20, "lat_long", &array, 2, sizeof(double), &imprimir_double, &escribir_en_archivo_double);
	njson_agregar_dato(&nodo21, "time_taken", "Wed, 28 Aug 2013 18:12:02 +0000", 1,
								sizeof("Wed, 28 Aug 2013 18:12:02 +0000"), &imprimir_string, &escribir_en_archivo_string);

	/**
	 * Creación del Json terciario
	 */
	Njson* lista3[2] = { &nodo20, &nodo21 };
	json_init(&terciario, lista3, 2);

	/**
	 * Agrega el Json terciario a un nodo y mete los nodos en el Json
	 */
	njson_agregar_dato(&nodo19, "photo_info", &terciario, 1, sizeof(Json), &imprimir_json, &escribir_en_archivo_json);
	json_agregar_njson(&secundario, &nodo19);
	json_agregar_njson(&secundario, njson_agregar_dato(&nodo22, "is_dir", &is_dir2, 1, sizeof(bool), &imprimir_boolean, &escribir_en_archivo_boolean));
	json_agregar_njson(&secundario, njson_agregar_dato(&nodo23, "icon", "page_white_picture", 1,
						sizeof("page_white_picture"), &imprimir_string, &escribir_en_archivo_string));
	json_agregar_njson(&secundario, njson_agregar_dato(&nodo24, "root", "dropbox", 1,
						sizeof("dropbox"), &imprimir_string, &escribir_en_archivo_string));
	json_agregar_njson(&secundario, njson_agregar_dato(&nodo25, "mime_type", "image/jpeg", 1,
						sizeof("image/jpeg"), &imprimir_string, &escribir_en_archivo_string));
	json_agregar_njson(&secundario, njson_agregar_dato(&nodo26, "revision", &revision, 1, sizeof(int), &imprimir_int, &escribir_en_archivo_int));
	njson_agregar_dato(&nodo11, "contents", &secundario, 1, sizeof(Json), &imprimir_json, &escribir_en_archivo_json);
	json_agregar_njson(&principal, &nodo11);
	json_agregar_njson(&principal, njson_agregar_dato(&nodo27, "revision", &revision2, 1, sizeof(int), &imprimir_int, &escribir_en_archivo_int));

	/**
	 * Modifica el valor de un nodo
	 */
	njson_cambiar_valor(&principal, "Bytes", &nuevobytes, 1, sizeof(int), &imprimir_int, &escribir_en_archivo_int);

	/**
	 * CASO 1: IMPRIME JSON GENERAL-------NOTA: COMENTAR LOS DEMAS CASOS CUANDO SE ESTE PROBANDO UNO.
	 */
	/**
	 * Impresión del Json
	 */
	json_imprimir(&principal);

	if(argc==3 && strcmp(argv[1], "-f") == 0){
		FILE* archivo_de_salida = fopen(argv[2], "w+");
		json_escribir_en_archivo(archivo_de_salida,&principal);
	}else{
		json_escribir_en_archivo(fopen("principal.json", "w+"),&principal);
	}

	/**
	 * Libera la memoria
	 */
	json_liberar(&terciario);
	json_liberar(&secundario);
	json_liberar(&principal);

	/**
	 * FIN DEL CASO 1
	 */






	/**
	 *
	 * CASO 2: CAMBIAR NODO CONTEST POR EL VALOR 1-------NOTA: COMENTAR LOS DEMAS CASOS CUANDO SE ESTE PROBANDO UNO.
	 *
	 */
//	json_liberar(&terciario);
//	json_liberar(&secundario);
//	int nuevo_valor = 1;
//	njson_cambiar_valor(&principal,"contents",&nuevo_valor,1,sizeof(int),&imprimir_int, &escribir_en_archivo_int);
//
//	json_imprimir(&principal);
//
//    if(argc==3 && strcmp(argv[1], "-f") == 0){
//	    FILE* archivo_de_salida = fopen(argv[2], "w+");
//	    json_escribir_en_archivo(archivo_de_salida,&principal);
//	}else{
//		json_escribir_en_archivo(fopen("principal.json", "w+"),&principal);
//	}
//
//    json_liberar(&principal);

    /**
     * FIN CASO 2
     *
     */






    /**
    *
    * CASO 3: METER UN NODO AL JSON, COMO VALOR UN ARREGLO [1,2,3]-------NOTA: COMENTAR LOS DEMAS CASOS CUANDO SE ESTE PROBANDO UNO.
    *
    */

//    int arreglo[3];
//    arreglo[0] = 1;
//    arreglo[1] = 2;
//    arreglo[2] = 3;
//    Njson nuevo_nodo;
//    njson_agregar_dato(&nuevo_nodo,"nuevo",&arreglo,3,sizeof(int),&imprimir_int, &escribir_en_archivo_int);
//    json_agregar_njson(&principal, &nuevo_nodo);
//
//    json_imprimir(&principal);
//
//    if(argc==3 && strcmp(argv[1], "-f") == 0){
//    	FILE* archivo_de_salida = fopen(argv[2], "w+");
//    	json_escribir_en_archivo(archivo_de_salida,&principal);
//    }else{
//    	json_escribir_en_archivo(fopen("principal.json", "w+"),&principal);
//    }
//
//    json_liberar(&terciario);
//    json_liberar(&secundario);
//    json_liberar(&principal);

    /**
     *
     * FIN CASO 3
     *
     */



}
