void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int arr[] = { val >> 24, (uint8_t)(val >> 16), (uint8_t)(val >> 8), (uint8_t) val };
    for (int i = 0; i < 4; i++)
    {
        avio_w8(s, arr[i]);
    }
}