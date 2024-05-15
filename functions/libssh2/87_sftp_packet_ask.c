sftp_packet_ask(LIBSSH2_SFTP *sftp, unsigned char packet_type,
                uint32_t request_id, unsigned char **data,
                size_t *data_len)
{
    LIBSSH2_SESSION *session = sftp->channel->session;
    LIBSSH2_SFTP_PACKET *packet = _libssh2_list_first(&sftp->packets);

    if(!packet)
        return -1;

    /* Special consideration when getting VERSION packet */

    while(packet) {
        if((packet->data[0] == packet_type) &&
           ((packet_type == SSH_FXP_VERSION) ||
            (packet->request_id == request_id))) {

            /* Match! Fetch the data */
            *data = packet->data;
            *data_len = packet->data_len;

            /* unlink and free this struct */
            _libssh2_list_remove(&packet->node);
            LIBSSH2_FREE(session, packet);

            return 0;
        }
        /* check next struct in the list */
        packet = _libssh2_list_next(&packet->node);
    }
    return -1;
}