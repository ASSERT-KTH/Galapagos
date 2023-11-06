void check(krb5_error_code code) 
{
    if (code == 0) {
        assert(true);
    } 
    else {
        const char* error_message = krb5_get_error_message(ctx, code);
        fputs(error_message, stderr);
        putc('\n', stderr);
        krb5_free_error_message(ctx, error_message);
        abort();
    }
}