Variant to verify whether the error-code is non-zero:

Function 1:


check(krb5_error_code code){
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        exit(1); 
    }
}


In this variant, the function will terminate the execution if the krb5 error code is non-zero, freeing the error message before termination. Furthermore, it doesn't assert the error code to be 0 like in the previous function, it simply terminates the function directly when non-zero error codes occur.

Function 2:


check(krb5_error_code code){
    const char *errmsg;

    if (code == 0) return;
    
    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    exit(1);
}


It directly validates and returns if the error code is equal to 0. If it is not validates, it follows the same structure as we have discussed earlier. It further verifies if the kvp error is non-zero to proceed over:
Writing an error message, freeing space occupied by the message, and stopping / terminating operation.

Function 3:


check(krb5_error_code code){
    if(!code)
        return;
    
    const char *errmsg;
    
    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(code == 0);  
}

The assert part of the code can appear despite knowing the code will be non-zero if this branch is reached. However, this will ensure the program ends as it would in a failed assert situation. The only different here is that the error message received will first be print and deallocated before assertion and termination.