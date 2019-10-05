/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "ftp.h"
#define DATA_SIZE UINT_MAX


	
void
read_ftp_server_1(char *host, char * fname, int cantBytes, int pos)
{
	CLIENT *clnt;
	ftp_file *result_1;
	
	char *filename = fname;
	uint64_t bytes = cantBytes;
	uint64_t initialPos = pos;

	ftp_req ftp_read_1_arg = {
		.name = filename,
		.pos = initialPos,
		.bytes = bytes,
	};

#ifndef	DEBUG
	clnt = clnt_create (host, FTP_PROG, FTP_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	printf("Haciendo llamado RPC para lectura\n");
	result_1 = read_1(ftp_read_1_arg, clnt);
	if (result_1 == (ftp_file *) NULL) {
		clnt_perror (clnt, "call failed");
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

void
write_ftp_server_1(char *host, char * fname, int cantBytes, char * buffer)
{
	printf("Comenzando llamado RPC para escritura\n");
	CLIENT *clnt;
	int  * result_2;
	ftp_file  ftp_write_1_arg;


	clnt = clnt_create (host, FTP_PROG, FTP_VERSION, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	
	
	printf("Haciendo llamado RPC para escritura\n");
	result_2 = write_1(&ftp_write_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	clnt_destroy (clnt);
}


int
main (int argc, char *argv[])
{
	char *host;
	char * method;
	char * fname;
	int cantBytes;
	host = argv[1];
	method = argv[2];
	fname = argv[3];
	cantBytes = atoi(argv[4]);
	if (method[0] == 'r'){
		if (argc < 6){
			fprintf(stderr, "Error faltan argumentos para lectura\n");
		}
		int pos;
		pos = atoi(argv[5]);
		printf("Enviando pedido de lectura\n");
		read_ftp_server_1(host, fname, cantBytes, pos);

	}else if(method[0] == 'w'){
		
		if (argc < 6){
			fprintf(stderr, "Error faltan argumentos para escritura\n");
		}
		printf("Enviando pedido de escritura\n");
		char * buffer;
		buffer = argv[5];
		write_ftp_server_1(host, fname, cantBytes, buffer);

	}else{
			fprintf(stderr, "Error metodo incorrecto");
	}

exit (0);
}
