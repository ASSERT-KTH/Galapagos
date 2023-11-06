Here is an alternative implementation of the function:


check(krb5_error_code code)
{
    if(code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr); 
        putchar('\n');

        krb5_free_error_message(ctx, errmsg);
    }
    assert(!code);
}


Justification of differences:

- `fputs` is used instead of `fprintf`, since only a string is printed.
- Explicit check for "non-zero" is replaced with `code`. In the context of an `if` statement, these count as the same thing.
- Instead of passing `"\n"` as parameter like in `fputs()`, `putchar('\n')` is used to achieve same effect.
- Instead of asserting `code == 0`, we assert `!code`, which effectively does the same thing.