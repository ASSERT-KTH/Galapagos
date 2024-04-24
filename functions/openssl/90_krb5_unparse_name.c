krb5_unparse_name(krb5_context context, krb5_const_principal principal,
                  char **name)
{
    if (name != NULL)                      /* name == NULL will return error from _ext */
        *name = NULL;

    return k5_unparse_name(context, principal, 0, name, NULL);
}