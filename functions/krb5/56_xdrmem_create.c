xdrmem_create(
	XDR *xdrs,
	caddr_t addr,
	u_int size,
	enum xdr_op op)
{

	xdrs->x_op = op;
	xdrs->x_ops = &xdrmem_ops;
	xdrs->x_private = xdrs->x_base = addr;
	xdrs->x_handy = (size > INT_MAX) ? INT_MAX : size; /* XXX */
}