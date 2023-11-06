Here is taking advantage of krb5_get_error_message() call, and reordering statements where it has not influenced the original behavior.


void check(krb5_error_code code)      
{      
    assert(code == 0);      
      
    if (code != 0) {      
        const char *errmsg = krb5_get_error_message(ctx, code);      
        fprintf(stderr, "%s\n", errmsg);      
        krb5_free_error_message(ctx, errmsg);      
    }      
}      


This version begins with the assertion. Thus, it grants a soft failure method when debug is on. In a regular application, the indication of failure will never be shown so it's as if it were placed at the end. Also, it will only execute the krb5 related heavy operations when an error exists. In this respect, it seems much effective.