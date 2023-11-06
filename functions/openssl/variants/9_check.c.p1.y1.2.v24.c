1. Using a ternary operator rather than an if statement:


check(krb5_error_code code)
{
    const char *errmsg;

    errmsg = (code != 0) ? krb5_get_error_message(ctx, code) : NULL;
    if (errmsg) {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}


2. Changing the order of lines (without affecting the order of execution) and combining declaration of errmsg with assignment:

 
check(krb5_error_code code)
{
    assert(code == 0);
  
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }   
}


3. Using else to emphasize assertion condition if the code does equals zero:


check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } else {
        assert(code == 0); 
    } 
}


4. Negating "!=0":


check(krb5_error_code code)
{
    if (!(code == 0)) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}
