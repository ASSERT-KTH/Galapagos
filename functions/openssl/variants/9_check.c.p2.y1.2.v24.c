check(krb5_error_code code)
{
    if (code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        
        if (errmsg)
        {
            fprintf(stderr, "%s\n", errmsg);;
            krb5_free_error_message(ctx, errmsg);
        }
        exit(EXIT_FAILURE);
    }
}