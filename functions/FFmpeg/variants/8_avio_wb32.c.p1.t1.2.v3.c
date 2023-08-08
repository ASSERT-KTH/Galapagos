void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int arr[4];
    arr[0] = val >> 24;
    arr[1] = (uint8_t)(val >> 16);
    arr[2] = (uint8_t)(val >> 8);
    arr[3] = (uint8_t)val;

    for(int i = 0; i < 4; i++) {
       avio_w8(s, arr[i]);
    }
}