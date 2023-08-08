void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int after_op;
    after_op = val >> 24;
    avio_w8(s, after_op);

    after_op = (uint8_t)(val >> 16);
    avio_w8(s, after_op);
    
    after_op = (uint8_t)(val >> 8);
    avio_w8(s, after_op);

    after_op = (uint8_t) val;
    avio_w8(s, after_op);
}