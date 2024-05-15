_libssh2_dh_key_pair(_libssh2_dh_ctx *dhctx, _libssh2_bn *public,
                     _libssh2_bn *g, _libssh2_bn *p, int group_order)
{
    /* Generate x and e */
    gcry_mpi_randomize(*dhctx, group_order * 8 - 1, GCRY_WEAK_RANDOM);
    gcry_mpi_powm(public, g, *dhctx, p);
    return 0;
}