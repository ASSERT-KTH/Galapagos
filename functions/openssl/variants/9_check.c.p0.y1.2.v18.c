Here is a different but equivalent substitute implementation of the function:


check(krb5_error_code code)
{
    const char *errmsg;

    do
    {
        if(code == 0) break;
        
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);

    } while(0);
    
    assert(code == 0);
}


The do-while loop runs only once and serves to break out of in the case code equals zero, which is the behavior of the conditional we are replacing. Since the body of the loop only executes once, the functionality remains the same.