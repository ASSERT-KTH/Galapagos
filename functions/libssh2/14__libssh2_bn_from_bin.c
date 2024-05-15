_libssh2_bn_from_bin(_libssh2_bn *bn, size_t len, const unsigned char *val)
{
    if(!BN_bin2bn(val, (int)len, bn)) {
        return -1;
    }

    return 0;
}