krb5_add_int_mem_ldap_mod(LDAPMod ***list, char *attribute, int op, int value)
{
    krb5_error_code ret;
    LDAPMod *mod;

    ret = alloc_mod(list, &mod);
    if (ret)
        return ret;

    mod->mod_type = strdup(attribute);
    if (mod->mod_type == NULL)
        return ENOMEM;

    mod->mod_op = op;
    mod->mod_values = calloc(2, sizeof(char *));
    if (mod->mod_values == NULL)
        return ENOMEM;
    mod->mod_values[0] = format_d(value);
    if (mod->mod_values[0] == NULL)
        return ENOMEM;
    return 0;
}