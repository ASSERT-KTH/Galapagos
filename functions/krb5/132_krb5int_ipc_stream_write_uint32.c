uint32_t krb5int_ipc_stream_write_uint32 (k5_ipc_stream io_stream,
                                          uint32_t      in_uint32)
{
    int32_t err = 0;
    int32_t uint32 = htonl (in_uint32);

    if (!io_stream) { err = k5_check_error (EINVAL); }

    if (!err) {
        err = krb5int_ipc_stream_write (io_stream, &uint32, sizeof (uint32));
    }

    return k5_check_error (err);
}