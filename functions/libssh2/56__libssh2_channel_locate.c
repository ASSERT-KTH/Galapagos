_libssh2_channel_locate(LIBSSH2_SESSION *session, uint32_t channel_id)
{
    LIBSSH2_CHANNEL *channel;
    LIBSSH2_LISTENER *l;

    for(channel = _libssh2_list_first(&session->channels);
        channel;
        channel = _libssh2_list_next(&channel->node)) {
        if(channel->local.id == channel_id)
            return channel;
    }

    /* We didn't find the channel in the session, let's then check its
       listeners since each listener may have its own set of pending channels
    */
    for(l = _libssh2_list_first(&session->listeners); l;
        l = _libssh2_list_next(&l->node)) {
        for(channel = _libssh2_list_first(&l->queue);
            channel;
            channel = _libssh2_list_next(&channel->node)) {
            if(channel->local.id == channel_id)
                return channel;
        }
    }

    return NULL;
}