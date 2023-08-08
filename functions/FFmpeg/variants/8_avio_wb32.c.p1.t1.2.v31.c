void avio_wb32(AVIOContext *s, unsigned int val)
{
    union {
        uint8_t bytes[4];
        unsigned int val;
    } value;

    value.val =  val;

    for (int i = 3; i >= 0; --i) {
        avio_w8(s, value.bytes[i]);
    }
}