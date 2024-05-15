libssh2_channel_write_ex(LIBSSH2_CHANNEL *channel, int stream_id,
                         const char *buf, size_t buflen)
{
    ssize_t rc;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    BLOCK_ADJUST(rc, channel->session,
                 _libssh2_channel_write(channel, stream_id,
                                        (unsigned char *)buf, buflen));
    return rc;
}