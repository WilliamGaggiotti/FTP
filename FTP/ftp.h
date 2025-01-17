/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _FTP_H_RPCGEN
#define _FTP_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct ftp_file {
	char *name;
	struct {
		u_int data_len;
		char *data_val;
	} data;
	uint64_t pos;
};
typedef struct ftp_file ftp_file;

struct ftp_req {
	char *name;
	uint64_t pos;
	uint64_t length;
};
typedef struct ftp_req ftp_req;

#define FTP_SERVER 0x20000001
#define VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define read_file 1
extern  ftp_file * read_file_1(ftp_req *, CLIENT *);
extern  ftp_file * read_file_1_svc(ftp_req *, struct svc_req *);
#define write_file 2
extern  int * write_file_1(ftp_file *, CLIENT *);
extern  int * write_file_1_svc(ftp_file *, struct svc_req *);
extern int ftp_server_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define read_file 1
extern  ftp_file * read_file_1();
extern  ftp_file * read_file_1_svc();
#define write_file 2
extern  int * write_file_1();
extern  int * write_file_1_svc();
extern int ftp_server_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_ftp_file (XDR *, ftp_file*);
extern  bool_t xdr_ftp_req (XDR *, ftp_req*);

#else /* K&R C */
extern bool_t xdr_ftp_file ();
extern bool_t xdr_ftp_req ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_FTP_H_RPCGEN */
