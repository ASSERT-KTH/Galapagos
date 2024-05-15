_libssh2_htonu32(unsigned char *buf, uint32_t value)
{
    buf[0] = (unsigned char)((value >> 24) & 0xFF);
    buf[1] = (value >> 16) & 0xFF;
    buf[2] = (value >> 8) & 0xFF;
    buf[3] = value & 0xFF;
}