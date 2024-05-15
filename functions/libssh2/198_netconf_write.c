static int netconf_write(LIBSSH2_CHANNEL *channel, const char *buf, size_t len)
{
    ssize_t i;
    ssize_t wr = 0;

    do {
        i = libssh2_channel_write(channel, buf, len);
        if(i < 0) {
            fprintf(stderr, "libssh2_channel_write: %ld\n", (long)i);
            return -1;
        }
        wr += i;
    } while(i > 0 && wr < (ssize_t)len);

    return 0;
}