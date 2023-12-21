1.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte;
    for(int shift = 24; shift >= 0; shift -= 8) {
        byte = (val >> shift) & 0xFF;
        avio_w8(s, byte);
    }
}

2.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (uint8_t)((val & 0xFF000000) >> 24));
    avio_w8(s, (uint8_t)((val & 0x00FF0000) >> 16));
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8 ));
    avio_w8(s, (uint8_t)(val & 0x000000FF       ));
}

3.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    int arr[4] = {val>>24, (uint8_t)(val>>16), (uint8_t)(val >> 8), (uint8_t)val};
    for(int i = 0; i < 4; i++) {
        avio_w8(s, arr[i]);
    }
}

4. 

void avio_wb32(AVIOContext *s, unsigned int val)
{
    memcpy(s->buffer + s->pos, &val, sizeof(val));
    s->pos += sizeof(val);
}