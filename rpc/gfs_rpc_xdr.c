#include "../include/gfs_rpc.h"

bool_t
xdr_open_args (XDR *xdrs, open_args *objp) {
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->oflags))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->mode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_close_args (XDR *xdrs, close_args *objp) {
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_read_args (XDR *xdrs, read_args *objp) {
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->count))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_read_res (XDR *xdrs, read_res *objp) {
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->ssize))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->buf, &objp->ssize, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_write_args (XDR *xdrs, write_args *objp) {
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->buf, &objp->nbytes, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_chk_info (XDR *xdrs, chk_info *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->ip, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}
