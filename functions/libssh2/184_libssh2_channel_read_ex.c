libssh2_channel_read_ex(LIBSSH2_CHANNEL *channel, int stream_id, char *buf,
                        size_t buflen)
{
    ssize_t rc;
    unsigned long recv_window;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    recv_window = libssh2_channel_window_read_ex(channel, NULL, NULL);

    if(buflen > recv_window) {
        BLOCK_ADJUST(rc, channel->session,
                     _libssh2_channel_receive_window_adjust(channel,
                                                   (uint32_t)buflen, 1, NULL));
    }

    BLOCK_ADJUST(rc, channel->session,
                 _libssh2_channel_read(channel, stream_id, buf, buflen));
    return rc;
}