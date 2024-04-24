int OPENSSL_strcasecmp(const char *s1, const char *s2)
{
    int t;

    while ((t = ossl_tolower(*s1) - ossl_tolower(*s2++)) == 0)
        if (*s1++ == '\0')
            return 0;
    return t;
}