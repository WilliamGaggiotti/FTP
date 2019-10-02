struct read_args{
    char * filename;
    int pos;
    int cantBytes;
};

struct write_args{
    char * filename;
    int cantBytes;
    char * buffer;
};

struct read_return{
    char * buffer_read;
    int cant_asked;
    int cant_read;
};

program FTP_SERVER {
    version FTP_VERSION{
        read_return leer() = 1;
        int escribir() = 2;
    } = 1;
} = 0x20000000001;