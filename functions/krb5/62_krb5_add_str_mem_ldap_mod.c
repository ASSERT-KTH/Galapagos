krb5_add_str_mem_ldap_mod(LDAPMod ***list, char *attribute, int op,
                          char **values)
{
    krb5_error_code ret;
    LDAPMod *mod;
    size_t count, i;

    ret = alloc_mod(list, &mod);
    if (ret)
        return ret;

    mod->mod_type = strdup(attribute);
    if (mod->mod_type == NULL)
        return ENOMEM;
    mod->mod_op = op;

    mod->mod_values = NULL;
    if (values == NULL)
        return 0;

    for (count = 0; values[count] != NULL; count++);
    mod->mod_values = calloc(count + 1, sizeof(char *));
    if (mod->mod_values == NULL)
        return ENOMEM;

    for (i = 0; i < count; i++) {
        mod->mod_values[i] = strdup(values[i]);
        if (mod->mod_values[i] == NULL)
            return ENOMEM;
    }
    mod->mod_values[i] = NULL;
    return 0;
}