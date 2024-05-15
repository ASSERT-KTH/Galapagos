find_zombie_request(LIBSSH2_SFTP *sftp, uint32_t request_id)
{
    struct sftp_zombie_requests *zombie =
        _libssh2_list_first(&sftp->zombie_requests);

    while(zombie) {
        if(zombie->request_id == request_id)
            break;
        else
            zombie = _libssh2_list_next(&zombie->node);
    }

    return zombie;
}