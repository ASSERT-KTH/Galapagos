static int channel_send_eof(LIBSSH2_CHANNEL *channel)
{
    LIBSSH2_SESSION *session = channel->session;
    unsigned char packet[5];    /* packet_type(1) + channelno(4) */
    int rc;

    _libssh2_debug((session, LIBSSH2_TRACE_CONN,
                   "Sending EOF on channel %u/%u",
                   channel->local.id, channel->remote.id));
    packet[0] = SSH_MSG_CHANNEL_EOF;
    _libssh2_htonu32(packet + 1, channel->remote.id);
    rc = _libssh2_transport_send(session, packet, 5, NULL, 0);
    if(rc == LIBSSH2_ERROR_EAGAIN) {
        _libssh2_error(session, rc,
                       "Would block sending EOF");
        return rc;
    }
    else if(rc) {
        return _libssh2_error(session, LIBSSH2_ERROR_SOCKET_SEND,
                              "Unable to send EOF on channel");
    }
    channel->local.eof = 1;

    return 0;
}