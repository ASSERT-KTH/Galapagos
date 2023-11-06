Using a compound conditional statement to deal with error instead of printing error every time and then asserting the condition:


check(krb5_error_code code)
{
    if (code == 0) {
        assert(1);
    } else {
        const char *errmsg;
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(0);
    }
}


NB. This version asserts the true statement when there is no error, and a false one when there is making the behavioural change slight (as opposed to the original version that always asserts code == 0 irrespective of the state).