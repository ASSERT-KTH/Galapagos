libssh2_channel_get_exit_status(LIBSSH2_CHANNEL *channel)
{
    if(!channel)
        return 0;

    return channel->exit_status;
}