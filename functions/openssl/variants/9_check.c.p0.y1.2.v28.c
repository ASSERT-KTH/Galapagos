Here's an equivalent function that accomplishes the same goal:


void check(krb5_error_code code)
{
    if (!code) {
        return;
    }

    const char *error_message = krb5_get_error_message(ctx, code);
    fputs(error_message, stderr);
    putc('\n', stderr);
    krb5_free_error_message(ctx, error_message);
    
    assert(code == 0);
}
