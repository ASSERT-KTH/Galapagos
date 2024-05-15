krb5_enctype_to_name(krb5_enctype enctype, krb5_boolean shortest,
                     char *buffer, size_t buflen)
{
    const struct krb5_keytypes *ktp;
    const char *name;
    int i;

    for (i = 0; unsupported_etypes[i].etype != ENCTYPE_NULL; i++) {
        if (enctype == unsupported_etypes[i].etype) {
            if (strlcpy(buffer, unsupported_etypes[i].name, buflen) >= buflen)
                return ENOMEM;
            return 0;
        }
    }

    ktp = find_enctype(enctype);
    if (ktp == NULL)
        return EINVAL;
    name = ktp->name;
    if (shortest) {
        for (i = 0; i < MAX_ETYPE_ALIASES; i++) {
            if (ktp->aliases[i] == NULL)
                break;
            if (strlen(ktp->aliases[i]) < strlen(name))
                name = ktp->aliases[i];
        }
    }
    if (strlcpy(buffer, name, buflen) >= buflen)
        return ENOMEM;
    return 0;
}