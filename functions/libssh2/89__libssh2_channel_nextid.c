_libssh2_channel_nextid(LIBSSH2_SESSION * session)
{
    uint32_t id = session->next_channel;
    LIBSSH2_CHANNEL *channel;

    channel = _libssh2_list_first(&session->channels);

    while(channel) {
        if(channel->local.id > id) {
            id = channel->local.id;
        }
        channel = _libssh2_list_next(&channel->node);
    }

    /* This is a shortcut to avoid waiting for close packets on channels we've
     * forgotten about, This *could* be a problem if we request and close 4
     * billion or so channels in too rapid succession for the remote end to
     * respond, but the worst case scenario is that some data meant for
     * another channel Gets picked up by the new one.... Pretty unlikely all
     * told...
     */
    session->next_channel = id + 1;
    _libssh2_debug((session, LIBSSH2_TRACE_CONN,
                   "Allocated new channel ID#%u", id));
    return id;
}