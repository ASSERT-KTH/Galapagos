cprinc_test_fail(char *user, kadm5_principal_ent_t ent, uint32_t mask,
                 char *pass, krb5_error_code code)
{
    void *handle = get_handle(user);

    check_fail(kadm5_create_principal(handle, ent, mask | KADM5_PRINCIPAL,
                                      pass), code);
    free_handle(handle);
}