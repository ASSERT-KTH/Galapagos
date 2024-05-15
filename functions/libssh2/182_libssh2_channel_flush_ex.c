libssh2_channel_flush_ex(LIBSSH2_CHANNEL *channel, int stream)
{
    int rc;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    BLOCK_ADJUST(rc, channel->session,
                 _libssh2_channel_flush(channel, stream));
    return rc;
}