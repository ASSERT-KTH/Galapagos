put32(struct k5buf *buf, int version, uint32_t num)
{
    char n[4];

    if (version < 3)
        store_32_n(num, n);
    else
        store_32_be(num, n);
    k5_buf_add_len(buf, n, 4);
}