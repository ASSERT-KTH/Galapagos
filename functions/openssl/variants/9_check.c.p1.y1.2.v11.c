Variant 1

If the name or the type of error number `code` was interfering with another name in your surrounding code, when working in the same scope, you may perform argument name substitutions. For example, using `err_code` instead of `code`.


check(krb5_error_code err_code)
{
    const char *errmsg;

    if (err_code != 0) {
        errmsg = krb5_get_error_message(ctx, err_code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(err_code == 0);
}


Variant 2

Instead of using the standard `assert()` to halt the program when encountering an error, using an `if()` statement could exit normally after the error has been printed.


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);

        if(code != 0){
		    exit(-1);
	    }
    }
}


Variant 3

Return the error after checking, instead of ending the program there. Later you could deal with it depending on the requirements of the function enclosing this one.


krb5_error_code check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }

	return code;
}
