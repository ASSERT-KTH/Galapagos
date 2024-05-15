libssh2_sftp_open_ex(LIBSSH2_SFTP *sftp, const char *filename,
                     unsigned int filename_len, unsigned long flags, long mode,
                     int open_type)
{
    LIBSSH2_SFTP_HANDLE *hnd;

    if(!sftp)
        return NULL;

    BLOCK_ADJUST_ERRNO(hnd, sftp->channel->session,
                       sftp_open(sftp, filename, filename_len, (uint32_t)flags,
                                 mode, open_type, NULL));
    return hnd;
}