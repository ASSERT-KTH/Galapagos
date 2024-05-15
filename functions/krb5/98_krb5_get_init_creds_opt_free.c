krb5_get_init_creds_opt_free(krb5_context context,
                             krb5_get_init_creds_opt *opt)
{
    struct extended_options *opte = (struct extended_options *)opt;
    int i;

    if (opt == NULL || !(opt->flags & GIC_OPT_EXTENDED))
        return;
    assert(!(opt->flags & GIC_OPT_SHALLOW_COPY));
    for (i = 0; i < opte->num_preauth_data; i++) {
        free(opte->preauth_data[i].attr);
        free(opte->preauth_data[i].value);
    }
    free(opte->preauth_data);
    free(opte->fast_ccache_name);
    free(opte);
}