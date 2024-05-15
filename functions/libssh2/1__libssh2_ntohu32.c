_libssh2_ntohu32(const unsigned char *buf)
{
    return ((uint32_t)buf[0] << 24)
         | ((uint32_t)buf[1] << 16)
         | ((uint32_t)buf[2] << 8)
         | ((uint32_t)buf[3]);
}