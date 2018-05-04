#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Json.h"

void generarJson(Json* this){
	this->size = "bytes";
	this->hash= "37eb1ba1849d4b0fb0b28caf7ef3af52";
	this->bytes = 056;
	this->thumb_exists = "false";
	this->rev = "714f029684fe";
	this->modified = "Wed, 27 Apr 2011 22:18:51 +0000";
	this->path = "/Photos";
	this->is_dir = "true";
	this->icon = "folder";
	this->root = "dropbox";
	this->photo_info->lat_long = 2453963;
	this->contents->size = "2.3 MB";
	this->contents->rev = "38af1b183490";
	this->contents->client_mtime = "Thu, 29 Aug 2013 01:12:02 +0000";
	this->contents->modified = "Mon, 07 Apr 2014 23:13:16 +0000";
	this->contents->path = "/Photos/flower.jpg";

}




void generarJsonEnArchivo(Json* json, char destino){

}
