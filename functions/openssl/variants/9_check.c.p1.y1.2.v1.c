Here are two variants of the function:

Variant 1 - Uses "!" instead of "!=" for the code comparison, and explicitly compares NULL against the error message obtained:


check(krb5_error_code code)
{
    const char *errmsg;

    if (!code) {
        errmsg = krb5_get_error_message(ctx, code);
        if (errmsg != NULL) {
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }    
    }
    assert(!code);
}


Variant 2 - Stores the error message in a specific pointer if the error code is not 0, and frees it if code verification through 'assert' fails:


check(krb5_error_code code)
{
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
    }
    
    if (errmsg) krb5_free_error_message(ctx, errmsg);
    assert(!code);
}
 

Please remember a friendly reminder that the usage of 'assert' in a production code base should be avoided, and instead you should consider using error handle/return. It's because 'assert' disappears if you define NDEBUG preprocessing directive before including assert.h or only works in DEBUG mode when the program crashes it will show a message in console not for the regular users.
Please treat these transformations as potential ways of altering the code preserving functionalities, rather on relying on them for specific use cases. Every transformation may not be 100% compatible to your program especially when dealing with implicit relationship.
