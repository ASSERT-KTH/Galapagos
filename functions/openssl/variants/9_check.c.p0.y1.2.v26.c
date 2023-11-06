Here's an equivalent substitute implementation in C:


check(krb5_error_code code)
{
    if (code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        putchar('\n');
        krb5_free_error_message(ctx, errmsg);
        code = 0;
    }
    
    assert(!code);
}

This code does exactly what the original function does. If 'code' is not 0, it fetches the associated error message for 'code' via the function 'krb5_get_error_message' into 'errmsg'. It then outputs this error message to the error stream. Unlike fprintf which can format output, 'fputs' and 'putchar' functions directly deal with strings and 'newline' respectively and serve the same purpose.
We update 'code' to zero and use the 'assert' macro (commonly used for debugging purpose to terminate program execution) which checks for the condition 'code' is 0 (not true will abort the program).