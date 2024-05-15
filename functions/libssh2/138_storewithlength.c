storewithlength(char *p, const char *data, int length)
{
    _libssh2_htonu32(p, length);
    if(length)
        memcpy(p + 4, data, length);
    return p + 4 + length;
}