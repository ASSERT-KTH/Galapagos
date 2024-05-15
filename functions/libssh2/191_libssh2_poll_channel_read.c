libssh2_poll_channel_read(LIBSSH2_CHANNEL *channel, int extended)
{
    LIBSSH2_SESSION *session;
    LIBSSH2_PACKET *packet;

    if(!channel)
        return LIBSSH2_ERROR_BAD_USE;

    session = channel->session;
    packet = _libssh2_list_first(&session->packets);

    while(packet) {
        if(packet->data_len < 5) {
            return _libssh2_error(session, LIBSSH2_ERROR_BUFFER_TOO_SMALL,
                                  "Packet too small");
        }

        if(channel->local.id == _libssh2_ntohu32(packet->data + 1)) {
            if(extended == 1 &&
                (packet->data[0] == SSH_MSG_CHANNEL_EXTENDED_DATA
                 || packet->data[0] == SSH_MSG_CHANNEL_DATA)) {
                return 1;
            }
            else if(extended == 0 &&
                    packet->data[0] == SSH_MSG_CHANNEL_DATA) {
                return 1;
            }
            /* else - no data of any type is ready to be read */
        }
        packet = _libssh2_list_next(&packet->node);
    }

    return 0;
}