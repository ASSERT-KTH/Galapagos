Here is an equivalent substitution of the mentioned function in C.


check(krb5_error_code code)
{
    if (0 != code) {
        const char *error_message;
        error_message = krb5_get_error_message(ctx, code);
        fputs(error_message, stderr);
        putc('\n', stderr);
        krb5_free_error_message(ctx, error_message);
    }
    assert(code == 0);
}

Please note that 'fputs' function is used instead of 'fprintf'. It places the string error_message on the stream stderr and append a new line character with putc. Rest of the logic remains same. We are still checking for krb5_error_code against zero and if true, fetching the error message with krb5_get_error_message, printing the message and freeing up the memory. We then ensure (by assert) that the error_code was indeed zero. This function offers the same functionality like the earlier one with simply different signature.