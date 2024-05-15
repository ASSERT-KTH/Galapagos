_libssh2_dh_key_pair(_libssh2_dh_ctx *dhctx, _libssh2_bn *public,
                     _libssh2_bn *g, _libssh2_bn *p, int group_order,
                     _libssh2_bn_ctx *bnctx)
{
    /* Generate x and e */
    BN_rand(*dhctx, group_order * 8 - 1, 0, -1);
    BN_mod_exp(public, g, *dhctx, p, bnctx);
    return 0;
}