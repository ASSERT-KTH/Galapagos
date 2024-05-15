_libssh2_dh_key_pair(_libssh2_dh_ctx *dhctx, _libssh2_bn *public,
                     _libssh2_bn *g, _libssh2_bn *p, int group_order)
{
    /* Generate x and e */
    _libssh2_mbedtls_bignum_random(*dhctx, group_order * 8 - 1, 0, -1);
    mbedtls_mpi_exp_mod(public, g, *dhctx, p, NULL);
    return 0;
}