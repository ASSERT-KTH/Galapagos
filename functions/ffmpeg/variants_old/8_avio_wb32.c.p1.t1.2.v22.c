void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char arr[4] = { 
        (unsigned char)(val >> 24), 
        (unsigned char)(val >> 16), 
        (unsigned char)(val >> 8), 
        (unsigned char)val 
    };

    for(int i = 0; i < 4; i++){
        avio_w8(s, arr[i]);
    }
}