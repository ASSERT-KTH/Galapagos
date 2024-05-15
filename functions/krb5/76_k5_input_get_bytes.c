k5_input_get_bytes(struct k5input *in, size_t len)
{
    if (in->len < len)
        k5_input_set_status(in, EINVAL);
    if (in->status)
        return NULL;
    in->len -= len;
    in->ptr += len;
    return in->ptr - len;
}