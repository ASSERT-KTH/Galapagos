_libssh2_dsa_new(libssh2_dsa_ctx ** dsactx,
                 const unsigned char *p,
                 unsigned long p_len,
                 const unsigned char *q,
                 unsigned long q_len,
                 const unsigned char *g,
                 unsigned long g_len,
                 const unsigned char *y,
                 unsigned long y_len,
                 const unsigned char *x, unsigned long x_len)
{
    int rc;

    if(x_len) {
        rc = gcry_sexp_build(dsactx, NULL,
                 "(private-key(dsa(p%b)(q%b)(g%b)(y%b)(x%b)))",
                  p_len, p, q_len, q, g_len, g, y_len, y, x_len, x);
    }
    else {
        rc = gcry_sexp_build(dsactx, NULL,
                             "(public-key(dsa(p%b)(q%b)(g%b)(y%b)))",
                             p_len, p, q_len, q, g_len, g, y_len, y);
    }

    if(rc) {
        *dsactx = NULL;
        return -1;
    }

    return 0;
}