#define MAX_PACKET_SIZE 512

struct ftp_file {
  string name<MAX_PACKET_SIZE>;
  opaque data<MAX_PACKET_SIZE>;
  uint64_t pos;
};

struct ftp_req {
  string name<MAX_PACKET_SIZE>;
  uint64_t pos;
	uint64_t length;
};

program FTP_SERVER {
  version VERSION {
    ftp_file read_file(ftp_req) = 1;
    int write_file(ftp_file) = 2;
  } = 1;
} = 0x20000001;
