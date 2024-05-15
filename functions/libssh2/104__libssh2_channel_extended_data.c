_libssh2_channel_extended_data(LIBSSH2_CHANNEL *channel, int ignore_mode)
{
    if(channel->extData2_state == libssh2_NB_state_idle) {
        _libssh2_debug((channel->session, LIBSSH2_TRACE_CONN,
                       "Setting channel %u/%u handle_extended_data"
                       " mode to %d",
                       channel->local.id, channel->remote.id, ignore_mode));
        channel->remote.extended_data_ignore_mode = (char)ignore_mode;

        channel->extData2_state = libssh2_NB_state_created;
    }

    if(channel->extData2_state == libssh2_NB_state_idle) {
        if(ignore_mode == LIBSSH2_CHANNEL_EXTENDED_DATA_IGNORE) {
            int rc =
                _libssh2_channel_flush(channel,
                                       LIBSSH2_CHANNEL_FLUSH_EXTENDED_DATA);
            if(LIBSSH2_ERROR_EAGAIN == rc)
                return rc;
        }
    }

    channel->extData2_state = libssh2_NB_state_idle;
    return 0;
}