Here is an equivalent C function which preserves the functionality of the initial code:


check(krb5_error_code code)
{
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, errmsg);
    }

    if (code) {
        abort();
    }
}


The equivalent function maintains nearly identical functionality: it outputs an error message if the condition is met, and aborts if it is. The output function `fputs()` is used instead of `fprintf()`. `fputs()` automatically inserts a newline character (`\n`), so a separate call is used for that. The `assert()` call is replaced by an equivalent `if` followed by `abort()`, lending greater transparency to the control flow. The code execution will stop if `abort()` is called.