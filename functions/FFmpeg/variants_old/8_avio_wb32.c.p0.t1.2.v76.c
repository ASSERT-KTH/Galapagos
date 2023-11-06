void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int aux = val;
    avio_w8(s,           aux >> 24 );
    aux = val;
    avio_w8(s, (uint8_t)(aux >> 16));
    aux = val;
    avio_w8(s, (uint8_t)(aux >> 8 ));
    aux = val;
    avio_w8(s, (uint8_t) aux       );
}