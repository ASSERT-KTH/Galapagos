int32_t krb5int_ipc_stream_new (k5_ipc_stream *out_stream)
{
    int32_t err = 0;
    k5_ipc_stream stream = NULL;

    if (!out_stream) { err = k5_check_error (EINVAL); }

    if (!err) {
        stream = malloc (sizeof (*stream));
        if (stream) {
            *stream = k5_ipc_stream_initializer;
        } else {
            err = k5_check_error (ENOMEM);
        }
    }

    if (!err) {
        *out_stream = stream;
        stream = NULL;
    }

    krb5int_ipc_stream_release (stream);

    return k5_check_error (err);
}