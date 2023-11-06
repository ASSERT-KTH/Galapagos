
void check(krb5_error_code code)
{
    if (code != 0) {
        const char *error_msg;
        error_msg = krb5_get_error_message(ctx, code);
        fputs(error_msg, stderr);
        krb5_free_error_message(ctx, error_msg);
        exit(1);
    }
}

The function now explicitly exits the program when an error is encountered, emulating the assert function's behavior when the assertion fails. Please note this variant is generally considered less safe than the original.