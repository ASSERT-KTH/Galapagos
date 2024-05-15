libssh2_channel_eof(LIBSSH2_CHANNEL * channel)
{
    LIBSSH2_SESSION *session;
    LIBSSH2_PACKET *packet;
    LIBSSH2_PACKET *next_packet;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    session = channel->session;
    packet = _libssh2_list_first(&session->packets);

    while(packet) {

        next_packet = _libssh2_list_next(&packet->node);

        if(packet->data_len < 1) {
            packet = next_packet;
            _libssh2_debug((channel->session, LIBSSH2_TRACE_ERROR,
                           "Unexpected packet length"));
            continue;
        }

        if(((packet->data[0] == SSH_MSG_CHANNEL_DATA)
            || (packet->data[0] == SSH_MSG_CHANNEL_EXTENDED_DATA))
            && ((packet->data_len >= 5)
            && (channel->local.id == _libssh2_ntohu32(packet->data + 1)))) {
            /* There's data waiting to be read yet, mask the EOF status */
            return 0;
        }
        packet = next_packet;
    }

    return channel->remote.eof;
}