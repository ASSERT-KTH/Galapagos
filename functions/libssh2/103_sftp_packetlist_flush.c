static void sftp_packetlist_flush(LIBSSH2_SFTP_HANDLE *handle)
{
    struct sftp_pipeline_chunk *chunk;
    LIBSSH2_SFTP *sftp = handle->sftp;
    LIBSSH2_SESSION *session = sftp->channel->session;

    /* remove pending packets, if any */
    chunk = _libssh2_list_first(&handle->packet_list);
    while(chunk) {
        unsigned char *data;
        size_t data_len;
        int rc;
        struct sftp_pipeline_chunk *next = _libssh2_list_next(&chunk->node);

        rc = sftp_packet_ask(sftp, SSH_FXP_STATUS,
                             chunk->request_id, &data, &data_len);
        if(rc)
            rc = sftp_packet_ask(sftp, SSH_FXP_DATA,
                                 chunk->request_id, &data, &data_len);

        if(!rc)
            /* we found a packet, free it */
            LIBSSH2_FREE(session, data);
        else if(chunk->sent)
            /* there was no incoming packet for this request, mark this
               request as a zombie if it ever sent the request */
            add_zombie_request(sftp, chunk->request_id);

        _libssh2_list_remove(&chunk->node);
        LIBSSH2_FREE(session, chunk);
        chunk = next;
    }
}