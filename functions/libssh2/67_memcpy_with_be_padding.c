memcpy_with_be_padding(unsigned char *dest, ULONG dest_len,
                       unsigned char *src, ULONG src_len)
{
    if(dest_len > src_len) {
        memset(dest, 0, dest_len - src_len);
    }
    memcpy((dest + dest_len) - src_len, src, src_len);
}