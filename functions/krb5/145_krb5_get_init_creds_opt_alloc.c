krb5_get_init_creds_opt_alloc(krb5_context context,
                              krb5_get_init_creds_opt **opt)
{
    struct extended_options *opte;

    if (opt == NULL)
        return EINVAL;
    *opt = NULL;

    /* Return an extended structure cast as a krb5_get_init_creds_opt. */
    opte = calloc(1, sizeof(*opte));
    if (opte == NULL)
        return ENOMEM;
    opte->opt.flags = DEFAULT_FLAGS | GIC_OPT_EXTENDED;
    opte->pac_request = -1;
    *opt = (krb5_get_init_creds_opt *)opte;
    return 0;
}