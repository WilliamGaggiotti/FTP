/*/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "ftp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


read_return *
leer_1_svc(read_args *argp, struct svc_req *rqstp)
{

	
	static read_return result;
	
	char * filename = argp->filename;
    int pos = argp->pos;
    int cantBytes = argp->cantBytes;
    //char * path = malloc(sizeof(char)*(strlen("./file_system_servidor/") + strlen(filename)));
    char path[100];
    strcpy(path, "./file_system_servidor/ejemplo");
    //printf("%s\n", filename);
    //strcat(path, filename);
    //printf("%s\n", path);
    char buf[cantBytes];
    result.buffer_read = malloc(sizeof(char) * cantBytes);
    FILE * fd = fopen(path, "r");
    result.cant_read = fread(result.buffer_read, sizeof(char), cantBytes, fd);
    result.cant_asked = cantBytes;
    fclose(fd);
    printf("%s\n", result.buffer_read);
    
	return (&result);
}

int *
escribir_1_svc(write_args *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
