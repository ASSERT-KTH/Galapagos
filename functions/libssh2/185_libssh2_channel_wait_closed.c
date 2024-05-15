libssh2_channel_wait_closed(LIBSSH2_CHANNEL *channel)
{
    int rc;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    BLOCK_ADJUST(rc, channel->session, channel_wait_closed(channel));
    return rc;
}