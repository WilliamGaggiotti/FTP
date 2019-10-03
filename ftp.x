typedef string file<100>;
typedef string buffer<100>;
struct read_args{
    file filename;
    int pos;
    int cantBytes;
};

struct write_args{
    file filename;
    int cantBytes;
    buffer buffer_write;
};

struct read_return{
    buffer buffer_read;
    int cant_asked;
    int cant_read;
};

program FTP_SERVER {
    version FTP_VERSION{
        read_return leer(read_args) = 1;
        int escribir(write_args) = 2;
    } = 1;
} = 55555556;
