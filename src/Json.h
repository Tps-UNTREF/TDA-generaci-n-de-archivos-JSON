
#ifndef JSON_H_
#define JSON_H_

struct _Contents{
	char* size,rev,thumb_exists,bytes,modified,client_mtime,path,is_dir,icon,root,mime_type;
	int revision;
	struct _Photo_info photo_info;
};

struct _Photo_info{
	double* lat_long[];
	char* time_taken;
};

typedef struct _Json {
	char* size,hash,thumb_exists,rev,modified, path,is_dir,icon,root;
	int bytes,revision;
	struct _Contents contents;

}Json;


void generarJson(Json* json);


#endif /* JSON_H_ */
