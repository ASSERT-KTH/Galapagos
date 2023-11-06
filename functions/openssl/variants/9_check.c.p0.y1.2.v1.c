Here is an equivalent but different implementation of your C function:

void check(krb5_error_code code)
{
    const char *msg;

    do 
    {
        if (code == 0) break;

        msg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", msg);
        krb5_free_error_message(ctx, msg);

    } while (code != 0);

    assert(code == 0);
}