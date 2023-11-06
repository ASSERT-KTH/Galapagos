Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (val >> 24) & 0xFF);
    avio_w8(s, (val >> 16) & 0xFF);
    avio_w8(s, (val >> 8) & 0xFF);
    avio_w8(s, val & 0xFF);
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    char *pData = (char *)&val + 3;
    avio_w8(s, *pData--);
    avio_w8(s, *pData--);
    avio_w8(s, *pData--);
    avio_w8(s, *pData);
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i = 3; i >= 0; i--)
        avio_w8(s, val >> (i * 8));
}


Variant 4:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char *pVal = reinterpret_cast<unsigned char*>(&val);
    for(int i = 0; i < 4; i++) {
        avio_w8(s, *(pVal+3-i));
    }
}
