/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc/gen/gfs_rpc.h"

bool_t
xdr_open_args (XDR *xdrs, open_args *objp)
{
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
xdr_close_args (XDR *xdrs, close_args *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_read_args (XDR *xdrs, read_args *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->buf, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->count))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_write_args (XDR *xdrs, write_args *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->fd))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->buf, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->nbytes))
		 return FALSE;
	return TRUE;
}
