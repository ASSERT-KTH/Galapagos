libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE *handle, libssh2_uint64_t offset)
{
    if(!handle)
        return;
    if(handle->u.file.offset == offset && handle->u.file.offset_sent == offset)
        return;

    handle->u.file.offset = handle->u.file.offset_sent = offset;
    /* discard all pending requests and currently read data */
    sftp_packetlist_flush(handle);

    /* free the left received buffered data */
    if(handle->u.file.data_left) {
        LIBSSH2_FREE(handle->sftp->channel->session, handle->u.file.data);
        handle->u.file.data_left = handle->u.file.data_len = 0;
        handle->u.file.data = NULL;
    }

    /* reset EOF to False */
    handle->u.file.eof = FALSE;
}