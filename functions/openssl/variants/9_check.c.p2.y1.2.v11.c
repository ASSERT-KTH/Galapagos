Here is a variant of the original code you provided. The main difference is that this code variant includes an explicit return statement, adding a level of redundancy to signal the outcome of the operation:


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(code == 0);
        return code; 
    }
    assert(code == 0); 
    return code; 
}


Despite the redundancy because of usage of an assert which will halt the program if the condition isn't satisfied, in case assert function is not compiled for some rules in production rules, our return will guarantee that the error isn't ignored.