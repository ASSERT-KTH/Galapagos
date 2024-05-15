check_princ(const char *name, krb5_principal expected_princ)
{
    krb5_ccache cache;
    krb5_principal princ;

    check(krb5_cc_resolve(ctx, name, &cache));
    if (expected_princ != NULL) {
        check(krb5_cc_get_principal(ctx, cache, &princ));
        assert(krb5_principal_compare(ctx, princ, expected_princ));
        krb5_free_principal(ctx, princ);
    } else {
        assert(krb5_cc_get_principal(ctx, cache, &princ) != 0);
    }
    krb5_cc_close(ctx, cache);
}