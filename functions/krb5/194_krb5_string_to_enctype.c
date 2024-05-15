krb5_string_to_enctype(char *string, krb5_enctype *enctypep)
{
    int i;
    unsigned int j;
    const char *alias;
    const struct krb5_keytypes *ktp;

    for (i = 0; i < krb5int_enctypes_length; i++) {
        ktp = &krb5int_enctypes_list[i];
        if (strcasecmp(ktp->name, string) == 0) {
            *enctypep = ktp->etype;
            return 0;
        }
        for (j = 0; j < MAX_ETYPE_ALIASES; j++) {
            alias = ktp->aliases[j];
            if (alias == NULL)
                break;
            if (strcasecmp(alias, string) == 0) {
                *enctypep = ktp->etype;
                return 0;
            }
        }
    }

    return EINVAL;
}