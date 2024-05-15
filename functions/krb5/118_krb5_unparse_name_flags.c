krb5_unparse_name_flags(krb5_context context, krb5_const_principal principal,
                        int flags, char **name)
{
    if (name != NULL)
        *name = NULL;
    return k5_unparse_name(context, principal, flags, name, NULL);
}