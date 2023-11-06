// Variant 1
void avio_wb32(AVIOContext *s, unsigned int val)
{
     for (int i = 24; i >= 0; i -= 8) {
         avio_w8(s, (uint8_t)(val >> i));
     }
}

// Variant 2
void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t *ptr = (uint8_t *)&val;
    avio_w8(s, ptr[3]);
    avio_w8(s, ptr[2]);
    avio_w8(s, ptr[1]);
    avio_w8(s, ptr[0]);
}

// Variant 3
void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4] = {  val >> 24, 
                         (val >> 16) & 0xFF, 
                         (val >> 8 ) & 0xFF, 
                          val        & 0xFF };
    for (int i = 0; i < 4; ++i) {
        avio_w8(s, bytes[i]);
    }
}

// Variant 4
void avio_wb32(AVIOContext *s, unsigned int val)
{
    union {
        unsigned int uint;
        uint8_t bytes[4];
    } hashmap;

    hashmap.uint = val;
    avio_w8(s, hashmap.bytes[3]);
    avio_w8(s, hashmap.bytes[2]);
    avio_w8(s, hashmap.bytes[1]);
    avio_w8(s, hashmap.bytes[0]);
}