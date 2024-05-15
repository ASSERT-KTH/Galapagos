krb5_ldap_put_handle_to_pool(krb5_ldap_context *ldap_context,
                             krb5_ldap_server_handle *ldap_server_handle)
{
    if (ldap_server_handle != NULL) {
        HNDL_LOCK(ldap_context);
        krb5_put_ldap_handle(ldap_server_handle);
        HNDL_UNLOCK(ldap_context);
    }
    return;
}