
#ifndef JSON_H_
#define JSON_H_

typedef struct _Contents{
	char size,rev,thumb_exists,bytes,modified,client_mtime,path,is_dir,icon,root,mime_type;
	int revision;
}_C;

struct _Photo_info{
	double lat_long[16];
	char time_taken;
};

typedef struct _Json {
	char size,hash,thumb_exists,rev,modified, path,is_dir,icon,root;
	int bytes,revision;
	struct _Photo_info photo_info;
	struct _Contents contents;

}Json;


void generarJson(Json* this);
void generarJsonEnArchivo(Json* this, char destino);


#endif /* JSON_H_ */
