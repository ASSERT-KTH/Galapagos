cpol_test_fail(char *user, kadm5_policy_ent_t ent, uint32_t mask,
               krb5_error_code code)
{
    void *handle = get_handle(user);

    check_fail(kadm5_create_policy(handle, ent, mask | KADM5_POLICY), code);
    free_handle(handle);
}