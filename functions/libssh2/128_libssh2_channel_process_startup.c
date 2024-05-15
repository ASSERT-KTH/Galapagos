libssh2_channel_process_startup(LIBSSH2_CHANNEL *channel,
                                const char *req, unsigned int req_len,
                                const char *msg, unsigned int msg_len)
{
    int rc;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    BLOCK_ADJUST(rc, channel->session,
                 _libssh2_channel_process_startup(channel, req, req_len,
                                                  msg, msg_len));
    return rc;
}