struct read_args {
	char *name;
	int	pos;
	int cantBytes;
};

struct read_result {
	char *buffer_read;
	int cant_asked;
	int cant_read;			
};

struct write_args {
	char *name;
	int cant;
	char *buffer;
};

program SRV_FTP {
   version FTP_VERSION {
     read_result leer(read_args) = 1;
     int escribir(write_args) = 2;
   } = 1;
} = 555555555;
