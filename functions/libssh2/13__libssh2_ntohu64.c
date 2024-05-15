_libssh2_ntohu64(const unsigned char *buf)
{
    return ((libssh2_uint64_t)buf[0] << 56)
         | ((libssh2_uint64_t)buf[1] << 48)
         | ((libssh2_uint64_t)buf[2] << 40)
         | ((libssh2_uint64_t)buf[3] << 32)
         | ((libssh2_uint64_t)buf[4] << 24)
         | ((libssh2_uint64_t)buf[5] << 16)
         | ((libssh2_uint64_t)buf[6] <<  8)
         | ((libssh2_uint64_t)buf[7]);
}