mprinc_test_fail(char *user, kadm5_principal_ent_t ent, uint32_t mask,
                 krb5_error_code code)
{
    void *handle = get_handle(user);

    check_fail(kadm5_modify_principal(handle, ent, mask), code);
    free_handle(handle);
}