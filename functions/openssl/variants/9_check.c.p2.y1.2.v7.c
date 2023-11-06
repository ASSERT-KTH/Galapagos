Here is a variant of the original program in which the error message is written only if it does not equal NULL:


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        if (errmsg != NULL) {
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }
    }
    assert(code == 0);
}

Please replace my nonexistent 'ctx' variables with your own or change references to functions and variables in line with your codebase as they are place-holders.