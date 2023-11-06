1. Switching the if statement with a ternary operator and handling assertion error messages with strerror(errno).

void check(krb5_error_code code)
{
    const char *errmsg = (code != 0) 
                          ? krb5_get_error_message(ctx, code) 
                          : NULL;
    if (errmsg != NULL) {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    if (code != 0) {
        fprintf(stderr, "AssertionFailed: %s\n", strerror(errno));
        exit(-1);
    }
}

2. Putting the assertion statement in an else branch to emphasize the logical distinction.

void check(krb5_error_code code)
{
    const char *errmsg;
        
    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } else {
        assert(code == 0);
    }
}

3. Use the exit system call to bring the process to a halt if an assertion is triggered.

void check(krb5_error_code code)
{
    const char *errmsg;
    
    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        printf("Exiting due to error ...\n");
        exit(EXIT_FAILURE);
    }
    assert(code == 0);
}


Note: The transformations maintain the sanity of original implementation while enhancing error logs, providing an alternative to the basic way of calling functions, and showing alternative ways to stop the script when required. Results may vary based on the larger context of use.