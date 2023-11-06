1. Checking the code != 0 before internal operations:
 
void check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(code == 0);
    }
}


2. Using break inside while(1) loop:


void check(krb5_error_code code)
{
    while(1) {
        if (code != 0) {
            const char *errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }
        assert(code == 0);
        break;
   }
}


3. Using early return:


void check(krb5_error_code code)
{
    if (code == 0) {
        return;
    }
    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(code == 0);
}    


4. Using do-while(0) loop:


void check(krb5_error_code code)
{
    do {
        if (code != 0) {
            const char *errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }
        assert(code == 0);
    } while (0);
}


Note: The transformed code is syntactically correct but keep in mind that this code won't behave as expected at runtime if code isn't equal to 0 because of the assertion assertion.