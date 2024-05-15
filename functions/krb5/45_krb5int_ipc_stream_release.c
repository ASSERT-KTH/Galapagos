uint32_t krb5int_ipc_stream_release (k5_ipc_stream io_stream)
{
    int32_t err = 0;

    if (!err && io_stream) {
        free (io_stream->data);
        free (io_stream);
    }

    return err;
}