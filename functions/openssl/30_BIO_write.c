int BIO_write(BIO *b, const void *data, int dlen)
{
    size_t written;
    int ret;

    if (dlen <= 0)
        return 0;

    ret = bio_write_intern(b, data, (size_t)dlen, &written);

    if (ret > 0) {
        /* written should always be <= dlen */
        ret = (int)written;
    }

    return ret;
}