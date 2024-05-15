xdr_long(XDR *xdrs, long *lp)
{

	switch (xdrs->x_op) {
	case XDR_ENCODE:
		VALGRIND_CHECK_DEFINED(*lp);
		if (*lp > 0x7fffffffL || *lp < -0x7fffffffL - 1L)
			return (FALSE);

		return (XDR_PUTLONG(xdrs, lp));

	case XDR_DECODE:
		return (XDR_GETLONG(xdrs, lp));

	case XDR_FREE:
		return (TRUE);
	}
	return (FALSE);
}