libssh2_channel_close(LIBSSH2_CHANNEL *channel)
{
    int rc;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    BLOCK_ADJUST(rc, channel->session, _libssh2_channel_close(channel));
    return rc;
}