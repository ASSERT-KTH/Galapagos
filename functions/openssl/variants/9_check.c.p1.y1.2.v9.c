1.

void check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}

2.

void check(krb5_error_code code)
{
    const char *errmsg;
    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(!code);
}

3.

void check(krb5_error_code code)
{
    const char *errmsg;
    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        exit(1);
    }
}

4.

void check(krb5_error_code code)
{
    assert(!code);
    const char *errmsg;
    if (!code) 
    {
       return;
    } 
    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
}

Please note examples 3, and 4 subtly change the behaviour of the program. They are still preserving the main intent behind function i.e., triggering failure procedure on certain conditions. However, they behave differently under the assert statement.
In 3, rather than freezing the program frozen in a buggy state using assert (only in debug version), we are finishing it with an error exit status calling exit(1). This assures us the program won’t continue in the erroneous state in either debug or release version.
In 4, If the initial test of the error condition with assert fails and the program under execution is debug version, it captures a failure dump and then terminates the program preventing the context-specific error cleanup code from running.