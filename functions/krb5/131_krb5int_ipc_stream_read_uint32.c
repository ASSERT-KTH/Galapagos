uint32_t krb5int_ipc_stream_read_uint32 (k5_ipc_stream  io_stream,
                                         uint32_t      *out_uint32)
{
    int32_t err = 0;
    uint32_t uint32 = 0;

    if (!io_stream) { err = k5_check_error (EINVAL); }
    if (!out_uint32) { err = k5_check_error (EINVAL); }

    if (!err) {
        err = krb5int_ipc_stream_read (io_stream, &uint32, sizeof (uint32));
    }

    if (!err) {
        *out_uint32 = ntohl (uint32);
    }

    return k5_check_error (err);
}