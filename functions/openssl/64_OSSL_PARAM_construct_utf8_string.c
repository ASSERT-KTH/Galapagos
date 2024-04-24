OSSL_PARAM OSSL_PARAM_construct_utf8_string(const char *key, char *buf,
                                            size_t bsize)
{
    if (buf != NULL && bsize == 0)
        bsize = strlen(buf);
    return ossl_param_construct(key, OSSL_PARAM_UTF8_STRING, buf, bsize);
}