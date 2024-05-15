xdr_u_int32(XDR *xdrs, uint32_t *up)
{
	u_long ul;

	switch (xdrs->x_op) {

	case XDR_ENCODE:
		VALGRIND_CHECK_DEFINED(*up);
		ul = *up;
		return (xdr_u_long(xdrs, &ul));

	case XDR_DECODE:
		if (!xdr_u_long(xdrs, &ul)) {
			return (FALSE);
		}
		*up = ul;
		return (TRUE);

	case XDR_FREE:
		return (TRUE);
	}
	return (FALSE);
}