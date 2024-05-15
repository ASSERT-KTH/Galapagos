xdr_sizeof (xdrproc_t func, void *data)
{
        XDR x;
        struct xdr_ops ops;
        bool_t stat;

#ifdef GF_DARWIN_HOST_OS
        typedef bool_t (*dummyfunc1) (XDR *, int *);
#else
        typedef bool_t (*dummyfunc1) (XDR *, long *);
#endif
        typedef bool_t (*dummyfunc2) (XDR *, caddr_t, u_int);

        ops.x_putlong = x_putlong;
        ops.x_putbytes = x_putbytes;
        ops.x_inline = x_inline;
        ops.x_getpostn = x_getpostn;
        ops.x_setpostn = x_setpostn;
        ops.x_destroy = x_destroy;

        /* the other harmless ones */
        ops.x_getlong = (dummyfunc1) harmless;
        ops.x_getbytes = (dummyfunc2) harmless;

        x.x_op = XDR_ENCODE;
        x.x_ops = &ops;
        x.x_handy = 0;
        x.x_private = (caddr_t) NULL;
        x.x_base = (caddr_t) 0;

        stat = func (&x, data, 0);
        if (x.x_private)
                free (x.x_private);
        return (stat == TRUE ? (unsigned) x.x_handy : 0);
}