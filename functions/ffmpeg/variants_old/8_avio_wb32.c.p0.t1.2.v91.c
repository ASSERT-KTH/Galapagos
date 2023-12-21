void avio_wb32(AVIOContext *s, unsigned int val)
{
    if (NULL != s)
    {
        avio_w8(s,           (uint8_t)(val >> 24) & 0xFF);
        avio_w8(s, (uint8_t)((val >> 16) & 0xFF)      );
        avio_w8(s, (uint8_t)((val >> 8)  & 0xFF)      );
        avio_w8(s, (uint8_t)(val         & 0xFF)      );
    }
}