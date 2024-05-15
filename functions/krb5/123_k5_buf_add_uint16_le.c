k5_buf_add_uint16_le(struct k5buf *buf, uint16_t val)
{
    void *p = k5_buf_get_space(buf, 2);

    if (p != NULL)
        store_16_le(val, p);
}