1. Adding Error Handling for NULL error message

void check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        if (errmsg == NULL) {
            fprintf(stderr, "Error message not found for error code: %d\n", code);
            return;
        }
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        return;
    }
    assert(code == 0);
}

2. Using TempData to store error message

void check(krb5_error_code code)
{
    char errmsg[1024];

    if (code != 0) {
        strncpy(errmsg, krb5_get_error_message(ctx, code), sizeof(errmsg)-1);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        return;
    }
    assert(code == 0);
}

3. Print more details about error

void check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "Error Code %d: %s\n", code, errmsg);
        krb5_free_error_message(ctx, errmsg);
        return;
    }
    assert(code == 0);
}
