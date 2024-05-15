acl_check(kadm5_auth_moddata data, uint32_t op, krb5_const_principal client,
          krb5_const_principal target, struct kadm5_auth_restrictions **rs_out)
{
    struct acl_entry *entry;

    if (rs_out != NULL)
        *rs_out = NULL;

    entry = find_entry((struct acl_state *)data, client, target);
    if (entry == NULL)
        return KRB5_PLUGIN_NO_HANDLE;
    if (!(entry->op_allowed & op))
        return KRB5_PLUGIN_NO_HANDLE;

    if (rs_out != NULL && entry->rs != NULL && entry->rs->mask)
        *rs_out = entry->rs;

    return 0;
}