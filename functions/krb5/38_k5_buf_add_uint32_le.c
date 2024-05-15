k5_buf_add_uint32_le(struct k5buf *buf, uint32_t val)
{
    void *p = k5_buf_get_space(buf, 4);

    if (p != NULL)
        store_32_le(val, p);
}